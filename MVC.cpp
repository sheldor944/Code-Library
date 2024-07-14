
#include <bits/stdc++.h>
using namespace std;
#define MX 1002
vector<int> adjList[MX];
int parent[MX];
int dp[MX][2];
int solve(int u, bool isStation)
{
    if (adjList[u].size() == 0)
        return 0;
    if (dp[u][isStation] != -1)
        return dp[u][isStation];
    int sum = 0;
    for (int i = 0; i < adjList[u].size(); i++)
    {
        int v = adjList[u][i];
        if (v != parent[u])
        {
            parent[v] = u;

            if (isStation == 0)
                sum += solve(v, 1);
            else
                sum += min(solve(v, 0), solve(v, 1));
        }
    }
    return dp[u][isStation] = sum + isStation;
}
int main()
{
    int n, m;

    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    memset(parent, -1, sizeof(parent));
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
    }
    int ans = min(solve(1, 0), solve(1, 1));
    cout << ans << endl;
    return 0;
}