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
int dp[N][11];
 
 

 
int32_t main()
{
    int test ; cin >> test ; 
    while(test--)
    {
        int n , q ; 
        cin >> n >> q ; 
        vector<int> v ; 
        map<int, int> mp ; 
        for(int i = 0 ; i< n ; i++){
            int x ; cin >> x ; 
            v.push_back(x);
            mp[x]++; 
        }
        for(auto u : mp ){
            cout<< u.first <<" "<<u.second<<endl;
        }
        cout<<endl;
        int sz = n ; 
        
        while(q--){
            int x , y ; cin >> x >> y ; 
            if(y == v[x]){
                cout<<sz<<endl;
            }
            else {
                
            }
        }

    }
}
