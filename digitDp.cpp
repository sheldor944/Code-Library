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
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

// dp state position, reminder, tight, isPreviousAllZero, isThePreviousOdd
int dp[18][18][2][2];
// int a, b;
vector<int> v ;
int m , n ; 
int k ;

int f (int pos, int start,  int prevUsed, int isFirst , string &s )
{
    if(pos == (s.size()- ))

}

 

 
int32_t main()
{
   int test ; cin>> test ;
   int tc=1 ;  
   while(test--)
   {
        cout<<"Case "<<tc<<": ";
        tc++;
        cin >> m >> n ; 
        memset(dp, -1 , sizeof(dp));
        for(int i = 0 ; i< m ; i++)
        {
            int x; cin >> x ; 
            v.push_back(x);
        }

        cout<<f(0,0,1)<<endl;

        v.clear();

   }

}



