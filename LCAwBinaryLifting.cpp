#include<bits/stdc++.h>
using namespace std; 

const int N = 2e5+12 ; 
vector<int> adjList[N], treeIdx[N]; 
bool vis[N] ; 
int tin[N]; 
int tout[N]; 
int TIN = 0 ; 
int depth[N]; 
int Root[N];
map<int, map<int,int>> familyDepth; 

const int L = log2(N); 

int up[N][L+1]; 

void dfs(int u , int par, int root ){

    vis[u] = true ; 
    up[u][0] = par;
    depth[u] = depth[par] + 1 ;  
    if(u == 1){
        cout<<" depth "<< depth[u]<<endl; 
    }
    treeIdx[depth[u]].push_back(TIN); 
    tin[u] = TIN++ ;
    familyDepth[root][depth[u]]++; 
    Root[u] = root; 
   
    for(int i = 1 ; i <= L ; i++){
        up[u][i] = up [up[u][i-1]][i-1]; 
    } 

    for(auto v : adjList[u]){
        if(!vis[v]){
           
            dfs(v,u, root);
        }
    }
    tout[u] = TIN++; 
}

bool isAncestor(int u , int v ){
    if(tin[u] <= tin[v] and tout[u] >= tout[v]){
        return true; 
    }
    return false ; 
}

int lca(int u , int v ){
    if(isAncestor(u,v)){
        return u ;
    }
    else if(isAncestor(v,u)){
        return v;
    }
    else{
        for(int i = L ; i >=0 ; i--){
            if(!isAncestor(up[u][i], v)){
                u= up[u][i];
            }
        }
    }
    return up[u][0];
}

int main(){
    int n, q ; 
    cin >> n ; 
    for(int i = 1 ; i <= n ; i++){
        int x , y; cin >> x >> y ;
        if(x!= 0){
            adjList[y].push_back(x);
            adjList[x].push_back(x);
        }
    }
    dfs(1,1,1); 
    cin >> q ; 
    while(q--){
        int a , b ; 
        cin >> a >> b ; 
        int l = lca(a, b); 
        cout<<" lcaa "<<l<<endl;
        int dep1 = depth[l] - depth[a]; 
        int dep2 = depth[l] - depth[b]; 
        cout<<dep1<<" "<<dep2<<endl;
        if(dep1 != dep2){

            cout<<"00\n";
        }
        else{
            cout<<"hhh"<<endl;
            cout<<depth[l] <<" "<<depth[1]<<endl; 
            int ans = depth[l] - depth[1]; 
            cout<<ans<<endl; 
            ans++;
            cout<<"here";
            cout<<(ans)<<endl;
        }
    }

   
    
}

// case 1 : all them is in straight line  a b c- > if(depth of a,b is min then c is dest )
// observation 1 : take both lca L1(a,c), L2(b,c). 
//                 path for a is --> a to L1 to c
//                 path for b is --> b to L2 to c
//                 Now, let L1 be the ancestor of L2. Then counter path is L2->L1->C i.e (L1-L2) + max(L2-a, L2-b, L1-c)
