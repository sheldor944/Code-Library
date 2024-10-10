#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define endl "\n"
#define inf 1000000000000000000
//#define int long long int
#define ordered_set tree< int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
 
 
// IN this problem, we are considering each node, and counting how many
// k-length path contians this node, 
// Given a node u we know that any path in the tree either passes u or is completely contained in one of 
// u 's children's subtrees,
// So using centroid decomposition, if we choose u intelligently. Then there shall be at most log(n) computation.
// Total complexity will be (NlogN)
 
 
const int N = 2e5+100;
 
class CentroidDecomposition
{
private:
    int n,k;
    vector<int>graph[N];
    bool processed[N]; // processed[i] = i-th node has been removed from the graph, tearing the graph apart.
    int cnt[N];    // cnt[i] = number of i-length path from the centroid/root
    int subtree[N];
    int mx_depth;
    int parent[N];
 
public:
    long long int ans; // ans = total count of excatly k-length paths
 
 
    CentroidDecomposition()
    {
        this->n = 0;
        this->k = 0;
    }
 
    void addEdge(int u,int v)
    {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
 
    int dfs(int s,int p)
    {
        subtree[s] = 1;
        for(auto child: graph[s])
        {
            if(child == p || processed[child])
            {
                continue;
            }
            subtree[s] += dfs(child,s);
        }
        return subtree[s];
    }
 
    int centroid(int s,int p,int n)
    {
        for(auto child: graph[s])
        {
            if(child == p || processed[child])
            {
                continue;
            }
            if(subtree[child] > n/2)
            {
                return centroid(child,s,n);
            }
        }
        return s;
    }
 
    void build(int s,int p,int k)
    {
        this->k = k;
        int n = dfs(s,p);
        int c = centroid(s,p,n);
 
        processed[c] = true;
        cout<<c<<endl;
        do_for_centroid(c);
 
        for(auto child : graph[c])
        {
            if(processed[child])
            {
                continue;
            }
            build(child,c,k);
        }
    }
 
    void do_for_centroid(int c) // Here, we will calculate, how many paths that contains the centroid C
    {
        cnt[0] = 1; // for computation, we consider Centroid to Centroid, zero lenth path
 
        mx_depth = 0;
 
        for(auto child : graph[c])
        {
            if(processed[child])
            {
                continue;
            }
 
            // current depth = 1, since they are children
 
            dfs2(child, c, 1,true); // flag = true, means compute k-length path for this subtree.
 
 
            dfs2(child,c, 1, false);  // flag = false means calculate cnt[i], for each i-length path from the centroid to subtree node.
 
            // For each children, we get a different subtree,
            // We know that if we go from one subtree node, to another subtree node, we must visit the centroid.
            // Since we are calculating the k-length path that goes through centroid, we must process each subtree differently.
            // Also to avoid recomputation, we must use two different dfs2(), so that for each i, we dont count cnt[k-i], of the same subtree, case that won't visit through the centroid.
        }
 
        for(int i=0;i<=mx_depth+1;i++)
        {
            cnt[i] = 0; // clearing
        }
 
 
 
    }
 
 
    void dfs2(int s,int p,int depth, bool flag)
    {
        if(k - depth < 0)
        {
            return;
        }
        
        if(flag) // calculate k-length path
        {
            ans += cnt[k-depth];  // from all the visited different subtree, we get the count of k-depth path,
                                  // from this subtree we take current path, whoose length is dept, so total length of each path = k - depth + depth = k
 
        }
 
        else // flag = false 
        {
            cnt[depth]++;
        }
 
        mx_depth = max(depth, mx_depth);
 
        for(auto child : graph[s])
        {
            if(child == p || processed[child] || child == s)
            {
                continue;
            }
 
            dfs2(child,s,depth+1,flag);
        }
    }
 
 
} CD; 
 
 
      
int32_t main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);
 
        int n,k;
        cin>>n>>k;
 
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            CD.addEdge(a,b);
        }
 
        CD.build(1,1,k);
 
 
        cout<<CD.ans<<endl;
 
        
 
}