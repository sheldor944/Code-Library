#include<bits/stdc++.h>
using namespace std; 

const int N = 3e5+12 ; 
vector<int> adjList[N]; 
bool vis[N] ; 
int tin[N]; 
int tout[N]; 
int TIN = 0 ; 
int depth[N]; 
const int L = 22; 

int up[N][L+1]; 

void dfs(int u , int par){
    vis[u] = true ; 
    tin[u] = TIN++ ;
    up[u][0] = par;
   
    for(int i = 1 ; i <= L ; i++){
        up[u][i] = up [up[u][i-1]][i-1]; 
    } 

    for(auto v : adjList[u]){
        if(!vis[v]){
            depth[v] = depth[u] + 1 ;  
           
            dfs(v,u);
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
    int n  ; 
    cin >> n ; 
    // cout<<n<<endl;
    for(int i = 1 ; i < n ; i++ ){
        int a , b ; cin >> a >> b ; 
        // cout<<a<<" "<<b<<endl;
        adjList[a].push_back(b); 
        adjList[b].push_back(a); 
    }
    dfs(1,1);
    int q ; 
    cin >> q ;  
    // cout<<q<<endl;
    // cout<<q<<endl;
    while(q--){
        int a , b , c ;
        cin >> a >> b >> c ; 
        // cout<<a1<<" "<<b1<<" "<<c1<<endl;
        int k = 0 ; 
        int st = - 1; 
        if(isAncestor(a,b)){
            // cout<<"here\n";
            k = depth[b] - depth[a];
            if(k <= c){
                cout<<b<<endl;
                continue;
            }
            else{
                // cout<<"ono\n";             
                st = 2 ; 
                k = k-c ; 
            }
        }
        else if(isAncestor(b,a)){
            // cout<<"here2\n";
            k = depth[a] - depth[b];
            if( k <=c){
                cout<<b<<endl;
                continue;
            }
            else{
                st = 1 ; 
                k = k  ; 
            }
        }
        else{
            int l = lca(a,b); 
            // cout<<l<<endl;
            // cout<<a<<" "<<b<<endl;
            
            if(depth[a] - depth[l] >= c){
                // cout<<"condition 1\n";
                k = c ;
                // cout<<k<<endl;
                // cout<<c<<endl;
                st = 1 ; 
            }
            else{
                // cout<<"condition 2\n";
                // int dep = (depth[a] - depth[l]) ;
                // cout<<l<<endl; 
                // cout<<dep<<endl;
                // int dep2 = (depth[b] - depth[l]); 
                // cout<<dep2<<endl;

                k = (depth[b] - depth[l]) - (c-(depth[a] - depth[l])); 
                if(k <=0){
                    cout<<b<<endl;
                    continue;
                }
                st = 2; 
            }
        }
        int node = -1; 
        if(st == 1 ){
            node = a ; 
            // cout<<k<<endl;
            for(int i = 0 ; i <=L ; i++){
                if(k&(1<<i)){
                    node = up[node][i];
                }
            }
        }
        else{
            node = b ; 
            for(int i = 0 ; i <=L ; i++){
                if(k&(1<<i)){
                    node = up[node][i];
                }
            }
        }
        // cout<<"here"<<endl;
        cout<<node<<endl;
        // cout<<endl;

    }
    
}
