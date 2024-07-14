#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int> >> adj;
int vis[100000];
int dis1[100000];
int dis2[100000];

int n ; 

void dijkstra(int src, int dis[] )
{
    for(int i = 0 ; i < n ; i++)
    {
        dis[i]= INT_MAX;
    }
    dis[src] = 0 ; 
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int> > > pq ; 
    pq.push({0,src});
    

    while(!pq.empty())
    {
        pair<int,int> p = pq.top();
        int cost = p.first;
        int node = p.second;
        pq.pop();
        if(vis[node])continue;
       

        vis[node]=1;
        for(auto u : adj[node])
        {
            if(dis[u.first] >  cost  + u.second )
            {
                dis[u.first] = u.second + cost ; 
                pq.push({dis[u.first] , u.first});
            }
        }
         cout<<node <<" "<<cost <<endl; 
    }

}


int main()
{   
    int m ; 
    cin >> n >> m ; 
    adj.resize(n);
    for(int i = 0 ; i< m ; i++)
    {
        int u , v , w ; 
        cin >> u >> v >> w ; 
        adj[u].push_back({v,w});
        // adj[v].push_back({u,w});
    }
    dijkstra(1 , dis1);
    // dijkstra(50 , dis2);
    // vector<int> ans ( 51 , 0);
    // for(int i = 1 ; i<=n ; i++)
    // {
    //     cout<<dis1[i]<<" ";
    // }
    // int mn = INT_MAX , idx = -1 ;
    // for(int i = 1 ; i<=50 ; i++)
    // {
    //     if(mn > ans[i])
    //     {
    //         mn = ans[i];
    //         idx = i ; 
    //     }
    // }
    // cout<<idx <<endl;
}

