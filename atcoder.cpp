#include <bits/stdc++.h>
using namespace std;

// vector<priority_queue<int>> adjList;
const int N = 2e5 + 123;
vector<int > adjList[N] , vis ; 

void dfs(int src )
{
    vis[src] = 1 ; 
    for(auto u : adjList[src])
    {
        if(!vis[u])
        {
            dfs(u);
            cout<<u<<" ";
        }
    }    
}

int main()
{
   int n ; 
   cin >> n ; 
   for(int i = 1 ; i<= n ; i++)
   {
        int c ; 
        cin >> c ;
        for(int j = 0; j < c ; j++)
        {
            int x ; 
            cin >> x ; 
            adjList[i].push_back(x);
        }
   }
    queue<int> q ; 
    q.push(1 );
    vis.resize(n+1 , 0 );
    vector<int> ans ; 
    // while(!q.empty())
    // {
    //     int node = q.front(); 
    //     q.pop();
    //     if(vis[node])continue;

    //     vis[node]= 1 ; 
    //     for(auto u : adjList[node])
    //     {
    //         ans.push_back(u);
    //         q.push(u);
    //     }
    // }
    dfs(1);
    // for(auto i : ans)
    // {
    //     cout<<i <<" ";
    // }
    cout<<endl;
}