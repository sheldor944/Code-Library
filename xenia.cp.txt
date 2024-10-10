#include<bits/stdc++.h>
using namespace std ; 

const long long  N = 2e5 + 1 ; 


class CentroidDecomposition{
    private: 
        long long  n , k1, k2 ; 
        vector<long long > adjList[N]; 
        bool processed[N]; 
        
        long long  subtree[N]; 
        long long  max_depth; 
        long long  cnt[N]; 
        long long  mx_depth = 0 ; 
        set<int> idx ; 
        int pref[N] ; 
        int Tree[4*N]; 

    
    public: 

        long long  ans = 0 ; 
        
        CentroidDecomposition(){
            this-> n = 0 ; 
            this-> k1 = 0 ;
            this-> k2 = 0 ; 

        }

        void buildSegmentTree(int node , int l , int r){
            if(l == r){
               Tree[node] = cnt[l]; 
               return ;  
                 
            }
            int mid = (l+r)/2 ; 
            buildSegmentTree(2*node , l , mid );
            buildSegmentTree(2*node + 1 , mid+1 , r); 
            Tree[node] = Tree[2*node] + Tree[2*node +1 ]; 
            return ;
        }
        int sum( int v , int tl , int tr, int l , int r ){
             if (l > r) 
                return 0;
            if( tl > r or l > tr){
                return 0 ; 
            }
            if (l == tl && r == tr) {
                return Tree[v];
            }
            int tm = (tl + tr) / 2;
            return sum(v*2, tl, tm, l, min(r, tm))
                + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
        }
        void update(int v, int tl, int tr, int pos, int new_val) {
            if (tl == tr) {
                Tree[v] = new_val;
            } else {
                int tm = (tl + tr) / 2;
                if (pos <= tm)
                    update(v*2, tl, tm, pos, new_val);
                else
                    update(v*2+1, tm+1, tr, pos, new_val);
                Tree[v] = Tree[v*2] + Tree[v*2+1];
            }
        }
        void addEdge(long long  u , long long  v){
            adjList[u].push_back(v);
            adjList[v].push_back(u); 
        }

        long long  dfs(long long  s , long long  p ){
            subtree[s] = 1 ; 
            for(auto u : adjList[s]){
                if(u == p || processed[u]){
                    continue;
                }
                subtree[s] += dfs(u,s); 
            }
            return subtree[s]; 
        }
        
        long long  centroid(long long  s , long long  p , long long  n){

            for(auto u : adjList[s]){
                if(u == p or processed[u]){
                    continue;
                }
                if(subtree[u]*2 > n){
                    // cout<<u<<" "<<s<<endl;
                    return centroid(u, s, n); 
                }
            }
            return s; 
        }

        void build(long long  s,long long  p, long long  k1, long long k2)
        {

                this-> k1 = k1 ;
                this-> k2 = k2 ;  

                long long  n = dfs(s,p);
                long long  c = centroid(s,p,n);

                processed[c] = true; 
                cout<<endl;
                cout<<c<<endl;
                do_for_centroid(c); 
               return ; 
                for( auto u : adjList[c]){
                    if(processed[u]){
                        continue;
                    }
                    build(u,c,k1, k2  );
                }
        }

        void do_for_centroid(long long  c){
            cnt[0] = 1 ; 
            pref[0] = 1 ; 
            mx_depth = 0 ; 
            int n = dfs(c, c); 
            cout<<n<<endl;
            // buildSegmentTree(1, 1, n); 
            for(long long  u : adjList[c]){
                if(processed[u]){
                    continue;
                }
                cout<<"child "<<u<<endl; 
                dfs2(u,c, 1 ,true); 
                dfs2(u,c, 1 ,false);
            }
            for(long long  i=0;i<=mx_depth+1;i++)
            {
                cnt[i] = 0;
            } for(long long  i=0;i<=(mx_depth+1)*4;i++)
            {
                Tree[i] = 0 ; 
            }
    

        }
        void dfs2(long long  s, long long  p , long long  depth, bool  flag  ){
            if(k2 - depth < 0 )
            {
                cout<<"here"<<endl ; 
                return;
            }
            mx_depth = max(mx_depth, depth); 
            cout<<"mx depth "<<mx_depth<<" "<<flag<<endl ; 
            if(flag)
            {
                cout<<"flag condition "<<flag<<endl ; 
                cout<<mx_depth<<" "<< k1-depth<<" "<<k2-depth<<endl;  
                int addition = sum(1, 0, mx_depth, k1-depth,  k2-depth); 
                cout<<addition<<endl;
                ans += addition;  
            }
            else {
                cnt[depth]++;
                cout<<"hello\n"; 

                update(1, 1, mx_depth, depth, cnt[depth]); 
                cout<<"hello\n"; 
            }
            for(auto u : adjList[s]){
                if(processed[u] ||  u == p or u == s){
                    continue;
                }
                dfs2(u,s, depth+1, flag); 
            }
            
        }

}centroidDecomposition;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long  n, k1, k2 ; 
    cin >> n >> k1>>k2  ; 

    for(long long  i = 1 ; i < n ; i++){
        long long  a , b ; cin >> a >> b ; 
        centroidDecomposition.addEdge(a,b); 
    }
    centroidDecomposition.build(1,1,k1, k2 ); 
    cout<<endl; 
    cout<<centroidDecomposition.ans<<endl;
  

}