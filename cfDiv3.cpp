#include<bits/stdc++.h>
using namespace std;

#define ll long long 
const int N = 1e7;
vector<int > adjList [N];
int visited[N];
int parent[N];


int dfs(int v , int par)
{
    visited[v] = 1;
    for (int u : adjList[v]) {
        if(u == par) continue; // skipping edge to parent vertex
        if (visited[u] == 1) {
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    visited[v] = 2;
    return false;
}



int main()
{
    ll test ;
    cin >> test;
    while(test--)
    {
        int n , m ; 
        cin >> n >>m ; 
        for(int j = 0 ; j< m ; j++)
        {
            vector< int > v ; 
            int oo ; 
            cin >> oo ; 
            for(int i = 0 ; i< n ; i++)
            {
                int x ; cin >> x ; 
                v.push_back(x);
            }
            for(int i = 0 ; i< n-2 ; i++ )
            {
                adjList[v[i]].push_back(v[i+1]);
            }
        }  
        for(int i = 0; i < n ; i++)
        {
            if(!visited[i+1])
            {
                
            }
        }


        



        

    }
}