#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
 
#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x << " is " << x << endl
#else
#define dbg(x)
#endif
 
const int MOD = 1e9 + 7 ; 
const int N = 1e6 + 123; 
int dp[101][N];
vector<int> v ; 


int solve(int i ,int n )
{
    if(n == 0   )
    {
        return 1 ; 
    }
    if(n<0) return 0 ; 
    if( i >= v.size()) return 0 ; 
    if(dp[i][n] != -1)return dp[i][n];

    return dp[i][n] = ( solve(i+1, n-v[i]) + solve(i+1, n));
}

 
int32_t main()
{
    int n, x ; cin >> n >> x;
    for(int i = 0 ; i< n ;i++)
    {
        int p ; cin >> p ; 
        v.push_back(p);
    }
    sort(v.begin() , v.end());
    memset(dp , -1 , sizeof(dp));     
    cout<<solve(0,x)<<endl;
    // cout<<((solve(x) == INT_MAX) ? -1 : solve(x))<<endl;
    // for(int i = 0 ; i<= 11 ; i++)
    // {
    //     cout<< dp[i]<<endl;
    // }
    // cout<<dp[1]<<" "<<dp[2]<<" "<<dp[3]<<endl;

}
