#include<bits/stdc++.h>
using namespace std;

const long long N = 2e5 + 123;

long long arr[N];
vector<long long> adjList[N];
long long down[N] , up[N] , par[N] , vis[N] , subTreeSum[N];

void dfs(long long src , long long p )
{
    for(long long u : adjList[src])
    {
        if(u == p)continue;
        dfs(u , src);
        subTreeSum[src] += subTreeSum[u] ;
        down[src] += down[u] + subTreeSum[u]  ;
        // cout<<" for node "<<src <<" ->"<< subTreeSum[src]<<" "<< down[src]<<" "<<down[u]<<" u is "<<u<<" "<<subTreeSum[u]<<endl;
    }
   
    // down[src] += subTreeSum[src];
    // cout<<" down of "<<src<<" "<<down[src] << ' ' << subTreeSum[src] <<endl;

}   
void dfs1(long long src , long long p)
{
    for(long long u : adjList[src])
    {
        if(u==p)continue;
       
        long long a =  (down[src] - down[u] - subTreeSum[u] + subTreeSum[src] - subTreeSum[u]) ;
        long long b = (up[src] +  (subTreeSum[1] - subTreeSum[src])   );
        long long c =  (subTreeSum[1] - subTreeSum[src]);
        // cout<<" c is "<<c<<endl;
        // cout<<" for node "<< u <<"  a is "<< a <<"  b is "<<b<<" up of src is "<<up[src] <<" src is "<<src <<endl ;
        up[u] += b + a; 
        dfs1(u , src);
    }
}

int main()
{
    long long n ; cin >> n ; 
    for(long long i = 1 ; i<= n ; i++)
    {
        cin >> arr[i];
        subTreeSum[i] = arr[i];
    }
    for(long long i = 0 ; i< n-1 ; i++)
    {
        long long a , b ; 
        cin >> a >> b ; 
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    dfs(1, -1 );

    // cout<<"subTree\n";
    // for(long long i = 0 ; i< n ; i++)
    // {
    //     cout<<subTreeSum[i+1]<<endl;
    // }
    // cout<<"Down\n";
    // for(long long i = 0 ; i< n ; i++)
    // {
    //     cout<<down[i+1]<<endl;
    // }
    dfs1(1,-1);

    // cout<<"Up\n";
    // for(long long i = 0 ; i< n ; i++)
    // {
    //     cout<<up[i+1]<<endl;
    // }
    // cout<<"ans\n";
    long long ans = 0; 
    for(long long i = 1 ; i <= n ; i++)
    {   
        ans = max(up[i]+down[i] , ans );
        // cout<<up[i]+down[i]<<endl;
    }
    cout<<ans<<endl;
}