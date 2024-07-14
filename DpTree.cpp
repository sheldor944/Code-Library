#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 123;

int arr[N];
vector<int> adjList[N];
int down[N] , up[N] , par[N] , vis[N] , subTreeSum[N];
map<int, int> mp ;
int cnt = 0 ;  
void dfs(int src , int p )
{
    int ind = 0 ;
    for(int u : adjList[src])
    {
        ind++;
        if(u == p)continue;
        dfs(u , src);
        // if parent and child emply swap them 
        if(mp.find(src) == mp.end() && mp.find(u) == mp.end())
        {
            cnt+= 2 ; 
            mp[src] = u ; 
            mp[u] = src; 
        }
        else if(mp.find(u) == mp.end()){
            cnt++ ; 
            mp[u] = mp[src] ; 
            mp[src] = u ; 
        }
    }   
    
}   

int main()
{
    int n ; cin >> n ; 
    for(int i = 0 ; i< n-1 ; i++)
    {
        int a , b ; 
        cin >> a >> b ; 
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    dfs(1,-1);
    // check for the root if a chain 1 -> 2 -> 3 
    if(mp.find(1) == mp.end())
    {
        int node = adjList[1][0]; 
        mp[1] = mp[node];
        mp[node] = 1 ; 
        cnt+= 2 ; 
        
    }
    cout<<cnt<<endl;
    for (const auto& pair : mp) {
        cout<<pair.second<<" ";
    }
    cout<<endl;

    
}