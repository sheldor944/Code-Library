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



vector<int>min_dist(100010,inf);

class CentroidDecomposition
{

public:
    int n,k;
    const static int N = 1e5+10;

        set<int>graph[N];  // many implementation uses 2d vector and isRemoved array , I however think using set is way simplier
        
        int subtree[N];
        int mx_depth;
        int parent[N];
        
        map<int,int>dist[N];

        


        CentroidDecomposition()
        {
                this->n = n;
                this->k = k;
        }

        void addEdge(int u,int v)
        {
                graph[u].insert(v);
                graph[v].insert(u);
        }

        int dfs(int s,int p)
        {
                subtree[s] = 1;
                for(auto child : graph[s])
                {
                        if(child == p )
                        {
                                continue;
                        }
                        subtree[s] += dfs(child,s);
                }
                return subtree[s];
        }

        int centroid(int s,int p,int n)
        {
                for(auto child : graph[s])
                {
                        if(child==p)
                        {
                                continue;
                        }
                        if(subtree[child]>n/2)
                        {
                                return centroid(child,s,n);
                        }
                }
                return s;
        }

        void build(int s,int p)
        {
                int n = dfs(s,p);
                int c = centroid(s,p,n);

                vector<int>temp(graph[c].begin() , graph[c].end());
         

                if(p == -1)
                {
                    parent[c] = c;
                }
                else 
                {
                    parent[c] = p;
                }

                DFS(c,p,c,0);

                for(auto child : temp)
                {
                        graph[child].erase(c);
                        graph[c].erase(child);

                        build(child , c);
                }


        }

        void DFS(int s,int p,int c,int depth)
        {
            dist[c][s] = depth;
            for(auto child : graph[s])
            {
                if(child == p)
                {
                    continue;
                }

                DFS(child, s, c, depth+1);
            }
        }

        void update(int x)
        {
            int take  = x;
            // cout<<take<<endl; 
            min_dist[x] = 0;
            while(x!= parent[x])
            {
                x = parent[x];
                // cout<<"parent "<<x<<endl; 
                // cout<<min_dist[x]<<" "<<dist[x][take]<<endl; 
                min_dist[x] = min(min_dist[x], dist[x][take]);
                // cout<<min_dist[x]<<endl; 
            }
        }

        int query(int x)
        {
            int p = x;
            int ans = min_dist[x];
            
            while(x != parent[x])
            {
                x = parent[x];
                ans = min(ans, min_dist[x] + dist[x][p]);
                
            }
            return ans;
        }



      

} CD;



      
int32_t main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        int n,q;
        cin>>n>>q;
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            CD.addEdge(a,b);
        }

        CD.build(1,-1);

        CD.update(1);

     


        while(q--)
        {
            int a,b;
            cin>>a>>b;
            if(a == 1)
            {
                CD.update(b);
            }
            else 
            {
               
                cout<<CD.query(b)<<endl;
            }
        }

}
