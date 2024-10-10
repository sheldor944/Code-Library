#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
 
#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x << " is " << x << endl
#else
#define dbg(x)
#endif
 
const int MOD = 1e9 + 7 ; 
const int N = 3e5 + 123; 
vector<int> v;
pair<int,int> treemMin[4*N];
pair<int,int> treemMax[4*N];

pair<int,int> customMin(pair<int,int>& p1, pair<int,int>& p2){
    if(p1.first<p2.first){
        return p1;
    }
    else if(p2.first< p1.first){
        return p2;
    }
    else{
        return (p1.second < p2.second) ? p1 : p2; 
    }
}
pair<int,int> customMax(pair<int,int>& p1, pair<int,int>& p2){
    if(p1.first > p2.first){
        return p1;
    }
    else if(p2.first>  p1.first){
        return p2;
    }
    else{
        return (p1.second < p2.second) ? p1 : p2; 
    }
}


void buildMin(int node , int a , int b)
{
    if(a==b){
        treemMin[node]={v[a], a};
        
        return ;
    }
    int mid=(a+b)/2;
    buildMin(2*node, a, mid);
    buildMin(2*node +1 , mid+1 , b);
    treemMin[node]= customMin(treemMin[node*2],treemMin[node*2 +1]);
}
pair<int,int> query(int node , int l , int r , int a , int b )
{
    if(l>b || r<a){
        return {INT_MAX, a};
    }
    if(l<=a && r>=b)
    {
        return treemMin[node];
    }
    int mid= (a+b)/2;
    pair<int,int> p1 = query(2*node , l , r , a , mid );
    pair<int,int> p2= query(2*node +1 , l , r , mid+1 , b);
    return customMin(p1, p2 );
}
void update(int idx , int v , int l , int r , int val)
{
    if(l == r )
    {
        treemMin[v]={val,l};
    }
    else{
        int mid = ( l + r)/2 ; 
        if(idx <= mid)
        {
            update(idx , 2*v , l , mid , val);
        }
        else{
            update(idx , 2*v + 1 , mid + 1, r , val);
        }
        treemMin[v] = customMin(treemMin[2*v] , treemMin[2*v + 1 ]);
    }
}


void buildMax(int node , int a , int b)
{
    if(a==b){
        treemMax[node]={v[a], a};
        return ;
    }
    int mid=(a+b)/2;
    buildMax(2*node, a, mid);
    buildMax(2*node +1 , mid+1 , b);
    treemMax[node]= customMax(treemMax[node*2],treemMax[node*2 +1]);
}
void updateMax(int idx , int v , int l , int r , int val)
{
    if(l == r )
    {
        treemMax[v]={val,l};
        return ; 
    }
    else{
        int mid = ( l + r)/2 ; 
        if(idx <= mid)
        {
            updateMax(idx , 2*v , l , mid , val);
        }
        else{
            updateMax(idx , 2*v + 1 , mid + 1, r , val);
        }
        treemMax[v] = customMax(treemMax[2*v] , treemMax[2*v + 1 ]);
    }
}
pair<int,int> queryMax(int node , int l , int r , int a , int b )
{
    if(l>b || r<a){
        return {INT_MIN, a};
    }
    if(l<=a && r>=b)
    {
        return treemMax[node];
    }
    int mid= (a+b)/2;
    pair<int,int> p1 =queryMax(2*node , l , r , a , mid );
    pair<int, int> p2 = queryMax(2*node +1 , l , r , mid+1 , b);
    return customMax(p1,p2 );
}
 
int32_t main()
{
    int test ; 
    cin >> test; 
    while(test--){
        int n ; cin >>n ;
        v.clear();
        v.resize(n+1,0);
        vector<vector<int>> range(n+1, vector<int>(2, 0));
        vector<int> adjList[n+1];
        for(int i = 1 ; i <=n ; i++){
            int x ; 
            cin >> x ; v[i] = x; 
            adjList[x].push_back(i);
            if(range[x][0] ==0){
                range[x][0] = i ;
                range[x][1] = i ;

            }
            else{
                range[x][1] = i ; 
            }
        }
        vector<int> ans;


        buildMin(1,1,n);
        buildMax(1,1,n);
        // pair<int,int> pp= queryMax(1,1,5,1,n);
        // cout<<pp.first<<" "<<pp.second<<endl;
        // update(3,1,1,n,90);
        // pair<int,int> p = query(1,1,5,1,n);
        // cout<<p.first<<" "<<p.second<<endl;
        int pos = 0 ;
        int left = 1 ;  
        int freq[n+1];
        memset(freq,0,sizeof(freq));


        // break ; 
        for(int i = 1 ; i <= n ; i++){
            // cout<<"i is "<<i<<" "<<n<<endl;
            if(range[v[i]][1] == i and freq[v[i]] == 0){
              
            //    cout<<i<<" "<<left<<endl;
                while(left<=i){
                    // cout<<"==> "<<left<<" "<<i<<endl; 
                    if((pos&1) == 0){
                        pair<int,int> p = queryMax(1,left,i,1,n);
                        if(freq[p.first] or p.first == 0 or p.first == 1e9){
                            left= p.second+1;
                            continue;
                        }
                        ans.push_back(p.first);
                        freq[p.first] = 1 ; 
                        for(int u : adjList[p.first]){
                            update(u,1,1,n,1e9);
                            updateMax(u,1,1,n,0);

                        }
                        left= p.second+1;
                        pos++;
                    }
                    else{
                        pair<int,int> p = query(1,left,i,1,n);
                         if(freq[p.first] or p.first == 0 or p.first == 1e9) {
                            left= p.second+1;
                            continue;
                        }
                        ans.push_back(p.first);
                        // cout<<p.first<<endl;
                        freq[p.first] = 1 ; 
                        // cout<<"indexes ";
                        for(int u : adjList[p.first]){
                            update(u,1,1,n,1e9);
                            updateMax(u,1,1,n,0);
                            // cout<<u<<" ";
                        } 
                        left= p.second+1;
                        pos++;
                        // cout<<"\nlast "<<left<<" "<<pos<<" "<<i<<endl;
                    }
                    if(freq[v[i]] == 1){
                        break;
                    }
                    // cout<<"--> "<<i<<" "<<left<<endl;
                }
            }
        }
        // cout<<"hello"<<endl;
        cout<<ans.size()<<endl;
        for(int u : ans){
            cout<<u<<" ";
        }
        cout<<endl;


        for(int i = 0 ; i <= 4*n +123; i++){
            treemMax[i] = {0,0};
            treemMin[i] = {0,0}; 
        }

        v.clear(); 
    }
}
