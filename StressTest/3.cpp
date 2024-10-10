//Intermediary
//Young kid on the block
//AIAsif try's Continuing the journey
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define endl "\n"
#define inf 1000000000000000000
#define int long long int
#define ordered_set tree< int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>

const int N = 3e5+100;
vector<int>graph[N];
int din[N];
int dout[N];
const int L = log2(N);
int up[N][L+1];
int sum[N];
int tim;


void dfs(int s, int par)
{
    up[s][0] = par;
    din[s] = tim++;

    for(int i = 1; i<= L; i++)
    {
        up[s][i] = up[up[s][i-1]][i-1];
    }

    for(auto child : graph[s])
    {
        if(child == par)
        {
            continue;
        }

        sum[child] = sum[s] + 1;

        dfs(child, s);
    }

    dout[s] = tim++;
}


bool is_ancestor(int u,int v)
{
    return (din[u] <= din[v] && dout[u] >= dout[v]);
}



int lca(int u,int v)
{
    if(is_ancestor(u,v))
    {
        return u;
    }

    if(is_ancestor(v,u))
    {
        return v;
    }

    for(int i=L; i>=0;i--)
    {
        if(!is_ancestor(up[u][i], v))
        {
            u = up[u][i];
        }
    }

    return up[u][0];
}


int k_th(int u, int k)
{

    for(int i = L; i>=0;i--)
    {
        if((1<<i) <= k)
        {
            k-=(1<<i);
            u = up[u][i];
        }
    }

    return u;

}      

int32_t main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        int n;
        cin>>n;
        for(int i=0;i<n-1;i++)
        {
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        dfs(1,1);

        int q;
        cin>>q;

        while(q--)
        {
            int a,b,c;
            cin>>a>>b>>c;

            int l = lca(a,b);

            //cout<<" lca "<<l<<endl;

            int path_len = sum[a] - sum[l] + sum[b] - sum[l];

            if(c>=path_len)
            {
                cout<<b<<endl;
                continue;
            }

            if(c <= (sum[a] - sum[l]))
            {
                cout<<k_th(a,c)<<endl;
                continue;
            }

            path_len -= c;


            cout<<k_th(b,path_len)<<endl;


        }



}
