#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adjList[300000];

vector<int> ans;
int done[300000];
int vis[300000];
 vector<int> deg;
int odd = 0, root = 0;
void dfs(int src)
{
    while (done[src] < adjList[src].size())
    {
        auto p = adjList[src][done[src]++];
        // edge visit checking
        if (vis[p.second])
            continue;
        vis[p.second] = 1;
        dfs(p.first);
    }
    ans.push_back(src);
}

int solve(int n)
{
    int edges = 0;
    vector<int> deg(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (auto e : adjList[i])
        {
            // deg[i]++;
            // deg[e.first]++;
            edges++;
        }
    }
   
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] & 1)
        {
            odd++;
            root = i;
        }
    }
    if (odd > 0)
        return 0;
    if (root == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            if (deg[i])
                root = i;
        }
    }
    if (root == 0)
        return 1;
    // cout<<odd<<endl;
    dfs(1);
    if (ans.size() != edges / 2 + 1)
        return 0;
    reverse(ans.begin(), ans.end());
    return 2;
}

int main()
{
    int n, m;
    cin >> n >> m;
    // vector<int> deg(n + 1, 0);
    deg.assign(n+1 , 0 );
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back({v, i});
        adjList[v].push_back({u, i});
        deg[u]++, deg[v]++;
    }
    int sz = m;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] & 1)
        {
            ++sz;
            odd++;
            // cout << "IMPOSSIBLE\n";
            // cout<<i<<endl;
            adjList[n + 1].push_back({i, sz});
            adjList[i].push_back({n + 1, sz});
        }
    }

    int ok = solve(n + 1);
    // cout<<ok <<endl;
    if (ok != 0)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
}