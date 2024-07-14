#include<bits/stdc++.h>
using namespace std;

const long long  N = 1e6 + 123;

long long  dp[100001][8];
long long  pref[N];
long long  available[N];
vector<int> v ; 
vector<string> s;
int n ;

int solve(int index , int mask )
{
    if(index == n){
        return 0;
    }
    if(mask == 7){
        return 0 ; 
    }

    if(dp[index][mask]!=-1){
        return dp[index][mask];
    }
    int cost = v[index];
    int curMask = 0 ; 
    for(int i = 0 ; i< s[index].size() ; i++)
    {
        int pos = s[index][i] - 'A' ;
        curMask |= (1<<pos); 
    }
    dp[index+1][mask] =dp[index][mask] +  solve(index+1 , mask);
    int newMask = curMask | mask ; 
    if( newMask != mask ){
        dp[index+1][newMask] = dp[index][mask] + cost + solve(index+1 , newMask);
    }
    return min(dp[index+1][newMask] , dp[index+1][mask]);
}


int  main()
{
    
    
   cin >> n ; 
   memset(dp , -1 , sizeof(dp));
   for(int i = 0 ; i< n ; i++)
    {
        int x ; cin >> x ; 
        string p ; cin >> p ; 
        v.push_back(x);
        s.push_back(p);
    }
    cout<<solve(0 , 0 );
    

 
}