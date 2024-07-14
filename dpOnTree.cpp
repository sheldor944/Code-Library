#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 3 ; 

vector<int> adjList[N] ;
int vis[N] , n , par[N];
int dp[2][N];
long long way[2][N];

long long mod = 101 ; 

int dfs(int src , int p )
{
    if(vis[src]) return max(dp[0][src], dp[1][src]); 
    vis[src]= 1 ; 

    for(auto u : adjList[src])
    {
        if(u == p) continue; 
        par[u] = src;
        dfs(u, src);
        dp[0][src] += max(dp[0][u] , dp[1][u]);
        dp[1][src] += dp[0][u];
        way[1][src] *= way[0][u];
        way[1][src] %= mod;

        if(dp[1][u] == dp[0][u]) {way[0][src] *= (way[1][u] + way[0][u]); way[0][src] %= mod;}
        if(dp[1][u] < dp[0][u]) {way[0][src] *= way[0][u]; way[0][src] %= mod;}
        if(dp[0][u] < dp[1][u]) {way[0][src] *= way[1][u]; way[0][src] %= mod ;}
    }
    dp[1][src]++;
    return max(dp[1][src], dp[0][src]);
}



int main()
{
    while(cin >> n )
    {
        if(n==0)break;
        for(int i = 0 ; i<= n ; i++)
        {
            adjList[i].clear();
            vis[i] = 0 ; par[i] = 0 ;  
            dp[1][i] = 0 ; 
            dp[0][i] = 0 ;
            way[1][i] = 1 ;
            way[0][i] = 1 ; 

        }
        string root ; 
        cin >> root ; 
        int ind = 1 ; 
        map<string, int > mp ; 
        mp[root] = ind ;
        // cout<<root<<" "<<mp[root]<<endl; 
        ind ++ ; 
        for(int i = 0 ; i< n-1 ; i++)
        {
            string a, b ; cin >> a >> b  ; 
            if(mp.count(a) <= 0){
                mp[a] = ind++;
                // cout<<a<<" "<<mp[a]<<endl;
            }
            if(mp.count(b) <=0 )
            {
                mp[b] = ind++ ; 
                // cout<<b<<" "<<mp[b]<<endl;

            }
            adjList[mp[a]].push_back(mp[b]);
            adjList[mp[b]].push_back(mp[a]);
            // cout<< mp[a] <<" "<<mp[b] <<endl;
        }
        // for (const auto& pair : mp) {
        // std::cout << pair.first << ": " << pair.second << std::endl;
        // }

        cout<<dfs(1,-1);
        // cout<<endl;
      

        long long  w = 0 ; 
        // cout<<dp[1][1] <<" "<< dp[0][1]<<endl;
        if(dp[0][1] > dp[1][1]){
            w = way[0][1];
        }
        else if(dp[0][1] < dp[1][1]){
            w = way[1][1];
        }
        else{
            // cout<<"here"<<endl;
            // cout<<way[1][1] <<" "<<way[0][1]<<endl;
            w = (way[1][1] + way[0][1]); 
        }
        if(w>1){
            cout<<" No\n";
        }
        else{
            cout<<" Yes\n";
        }
       
    }
}