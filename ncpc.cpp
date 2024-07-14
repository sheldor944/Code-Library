#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long 

const int N = 2e5 + 3 ; 
int n ; 

vector<int> adjList[N] ;
vector<int> vis;
int par[N];
int dp[N+1][2];
int siblings[N+1];

int dfs(int src , int p)
{
    if(vis[src])return max(dp[src][0] , dp[src][1]);

    vis[src] = 1;
    int mx = -1 ; 
    for(int u : adjList[src])
    {
        if(u==p) continue; 
        par[u] = src;
        dfs(u,src);
        dp[src][0] += max(dp[u][0] , dp[u][1]);
        // cout<<src<<" "<<u<<" dp[src][0] "<<dp[src][0] <<" dp[u][0] "<< dp[u][0] << " dp[u][1] "<<dp[u][1]<<endl;
        // mx = max(mx, dp[u][0]);

    }
   
    for(int i : adjList[src]){
        siblings[src] += dp[i][1];
    }
    if(adjList[src].size()>1)
    {
        for(int i : adjList[src])
        {
            if(i == par[src])continue;
            dp[src][1] = max(dp[i][0] + 1- dp[i][1] + siblings[src] , dp[src][1]);
            // cout<<" dp[src][1] " << src<< " "<<dp[src][1]<<endl;
        }

    }
    
    // if(adjList[src].size() == 1 ){
    //     cout<< src<< " jj" <<endl;
    //     dp[p][1] = max(1 , dp[p][1]); 
    //     // cout<<"DP of "<< p <<" "<< dp[p][1]<<endl;
    // }
    // else{
      
        // dp[src][1] = mx + 1;

    // }
    // cout<<" answer for "<< src << " "<<max(dp[src][0] , dp[src][1])<<endl;
   return max(dp[src][0] , dp[src][1]);
}


int main() {
	FastIO;
    cin >> n ; 
    vis.resize(n+5);
    vis.assign(n+5, 0 );
    memset(dp , 0 , sizeof(dp ));
    for(int i = 1 ; i< n ; i++)
    {
        int a , b ; cin >> a >> b; 
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    // for(int i = 2 ; i <= n ; i++ )
    // {
    //     int n = 10; // Define the upper limit (inclusive)

    //     std::random_device rd; // Obtain a random number from hardware
    //     std::mt19937 eng(rd()); // Seed the generator
    //     std::uniform_int_distribution<> distr(1, i-1); // Define the range [1, n]

    //     int random_number = distr(eng);
    //     adjList[i].push_back(random_number); 
    //     adjList[random_number].push_back(i); 
    //     cout<< i << " "<<random_number<<endl;

    // }
    if(n==2){
        cout<<1<<endl;
    }
    else{
    cout<<dfs(1,-1)<<endl;
   }
	return 0;
}


// 8 jj
// DP of 4 1
//  answer for 8 0
//  answer for 4 1
// 5 jj
// DP of 2 1
//  answer for 5 0
// 9 jj
// DP of 7 1
//  answer for 9 0
//  answer for 7 1
// 10 jj
// DP of 2 1
//  answer for 10 0
//  answer for 2 2
// 3 jj
// DP of 1 1
//  answer for 3 0
// 6 jj
// DP of 1 1
//  answer for 6 0
//  answer for 1 3
// 3