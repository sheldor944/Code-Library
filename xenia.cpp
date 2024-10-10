#include<bits/stdc++.h>
using namespace std ; 

const long long  N = 60000 ; 

int all[N] ; 

class CentroidDecomposition{
    private: 
        long long  n , k ; 
        vector<long long > adjList[N]; 
        bool processed[N]; 
        
        long long  subtree[N]; 
        long long  max_depth; 
        long long  cnt[N]; 
        long long  mx_depth = 0 ; 
    
    public: 

        long long  ans = 0 ; 
        
        CentroidDecomposition(){
            this-> n = 0 ; 
            // this-> k = 0 ; 
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

        void build(long long  s,long long  p)
        {

            long long  n = dfs(s,p);
            long long  c = centroid(s,p,n);

            processed[c] = true; 
            // cout<<c<<endl;
            do_for_centroid(c); 
            
            for( auto u : adjList[c]){
                if(processed[u]){
                    continue;
                }
                build(u,c);
            }
        }

        void do_for_centroid(long long  c){
            cnt[0] = 1 ; 
            mx_depth = 0 ; 
            
            for(long long  u : adjList[c]){
                if(processed[u]){
                    continue;
                }
                dfs2(u,c, 1 ,true); 
                dfs2(u,c, 1 ,false);
            }
            for(long long  i=0;i<=mx_depth+1;i++)
            {
                cnt[i] = 0;
            }
    

        }

        void dfs2(long long  s, long long  p , long long  depth, bool  flag  ){
          
            mx_depth = max(mx_depth, depth); 
            if(flag)
            {
                for(int i = 1 ; i <= mx_depth ; i++){
                    all[i+depth] += cnt[i]; 
                }
            }
            else {
                cnt[depth]++;
                all[depth]++; 
            }
            for(auto u : adjList[s]){
                if(processed[u] ||  u == p ){
                    continue;
                }
                dfs2(u,s, depth+1, flag); 
            }
            
        }

}centroidDecomposition;


vector<int> primes;
bool sieve[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i < N; i++)
    {
        if (!sieve[i])
        {
            primes.push_back(i);
            for (int j = i + i; j < N; j += i)
            {
                sieve[j] = true;
            }
        }
    }
    long long  n;
    cin >> n ;

    for(long long  i = 1 ; i < n ; i++){
        long long  a , b ; cin >> a >> b ; 
        centroidDecomposition.addEdge(a,b); 
    }
    centroidDecomposition.build(1,1); 
    long long ans = 0 ; 
    for (int i = 0; i < primes.size(); i++)
    {

        int k = primes[i];
        ans += all[k];
    }
     double total = n * 1LL * (n - 1) / 2.0;
   

    cout << setprecision(18) << ((ans * 1.00) / total) << endl;

   
  

}