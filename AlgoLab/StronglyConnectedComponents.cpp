#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList, adjListRev;
vector<bool> vis;
vector<int> order, component;

void dfs1(int src)
{
    vis[src] = true;
    for (auto u : adjList[src])
    {
        if (!vis[u])
        {
            dfs1(u);
        }
    }
    order.push_back(src);
}

void dfs2(int src)
{
    vis[src] = true;
    component.push_back(src);
    for (auto u : adjListRev[src])
    {
        if (!vis[u])
        {
            dfs2(u);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    adjList.resize(n + 1);
    adjListRev.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjListRev[v].push_back(u);
    }
    vis.assign(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs1(i);
        }
    }
    vis.assign(n + 1, false);

    reverse(order.begin(), order.end());

    vector<int> roots(n + 1, 0);
    vector<int> root_nodes;
    vector<vector<int>> adjScc(n + 1);

    for (auto i : order)
    {

        if (!vis[i])
        {
            // cout<<i<<" start \n";
            dfs2(i);

            int root = component.front();
            for (auto u : component)
                roots[u] = root;
            root_nodes.push_back(root);

            // for (auto u : component)
            // {
            //     cout << u << " ";
            // }
            // cout << endl;
            component.clear();
        }
    }

    for (int v = 1; v <= n; v++)
    for (auto u : adjList[v]) {
        int root_v = roots[v],
            root_u = roots[u];

        if (root_u != root_v)
            adjScc[root_v].push_back(root_u);
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (auto u : adjScc[i])
    //     {
    //         // cout <<i<<" ->"<< u << " \n";
    //     }
    //     cout << endl;
    // }
}