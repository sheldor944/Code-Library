#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ull unsigned long long

#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x << " is " << x << endl
#else
#define dbg(x)
#endif

int n  , m1 , m2 ; 
vector<int> v1, v2;



const int M = 1e9+7;
const int N = 5e5 + 11 ; 
 
int fact[N], invFact[N] , vis[N+12];
vector<int> adjList[N+12];


int diameter1(int src , int p )
{
    vis[src] = 1 ; 
    for(auto u : adjList[src])
    {
        if(u!=src)
    }
}

long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % N;
        p_pow = (p_pow * p) % N;
    }
    return hash_value;
}
multiset<pair<int, int>> mst;

int dfs(int src , int p )
{
    // vis[src]=1 ; 
    // cout<<"starting the dfs "<<endl;
    dbg("starting the dfs");
    for(auto u : mst){
            dbg(u.first);
            dbg(u.second);
            // cout<<u.first<<" "<<u.second<<endl;
        }
    
    int edges = 0 ; 
    for(int u: adjList[src])
    {
        int small = min(u, src);
        int big = max(u, src);
        // int small = src ; 
        // int big = u ; 
        if(mst.count({small, big}) >0){
            if(mst.find({small,big}) != mst.end()){
                mst.erase(mst.find({small, big}));
                // cout<<"after first deletion\n"; 
                dbg("afterDeletion ");
                for(auto u : mst){
                  dbg(u.first);
                  dbg(u.second);
                // cout<<u.first<<" "<<u.second<<endl;
                }
                edges += (1+ dfs(u,src));
                // cout<<edges <<" this is edges "<<endl;

            }
        }
    }
    // cout<<"returner edges "<<edges<<endl;
    return edges;
}


int32_t main()
{
    int test; 
    cin >> test ; 
    while(test--)
    {  
        int n ; cin >> n ;
        set<int> st;
        for(int i = 0 ; i < n ; i++)
        {
            string a , b ; cin >> a>> b ; 
            a+= "eitagenrekingoffifa";
            b+= "igusingertiktok";
            int hashA = compute_hash(a);
            int hashB = compute_hash(b);
            adjList[hashA].push_back(hashB);
            // cout<<hashA<<" "<<hashB<<endl;
            adjList[hashB].push_back(hashA);
            st.insert(hashA);
            st.insert(hashB);
            if(hashA > hashB){
                swap(hashA, hashB);
            }
            mst.insert({hashA , hashB});
        }
        int ans = -1 ; 
        for(auto u : mst){
                // dbg(u.first);
                // dbg(u.second);
        //     cout<<u.first<<" "<<u.second<<endl;
        }
        for(int i = 0 ; i<=N ; i++ )
        {
            if(!vis[i] && adjList[i].size())
            {  
                // dbg("this is called "+ i );

                ans = max(ans , dfs(i,-1));
            }
        }
        // cout<<ans<<endl;
        cout<< n - ans<<endl;
        mst.clear();
        for(auto u : st )
        {
            adjList[u].clear();
            vis[u]=0;
        }
    }
}