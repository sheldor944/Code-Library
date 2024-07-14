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
int dp[12][85][85][2];
int a, b;
int k ;


int f (int pos,int remainder,int sum, int tight, string &s  )
{
    if(pos == s.size())
    {
        return (remainder == 0  and sum % k == 0) ;
    }
    if(dp[pos][remainder][sum][tight] != -1) return dp[pos][remainder][sum][tight];

    int res = 0; 
    for(int i = 0 ; i<= (tight ? s[pos]-'0' : 9) ; i++)
    {
        res += f(pos+1 , ((remainder * 10)%k + i) % k , sum + i , (tight and i == s[pos]-'0') ,s);
    }
    return dp[pos][remainder][sum][tight] = res ; 

}

 

 
int32_t main()
{
   int test ; cin>> test ;
   int tc=1 ;  
   while(test--)
   {
        cout<<"Case "<<tc<<": ";
        tc++;
        cin >> a >> b;
        cin >> k; 
        if(k > 81){
            cout<<"0";
        }
        else{
            memset(dp, -1 , sizeof(dp));
            string s = to_string(b);
            // dbg(s);
            int ans1 = f(0, 0, 0, 1, s);
            memset(dp, -1 , sizeof(dp));
            string s2 = to_string(a-1);
            // dbg(s2);
            
            int ans2 = f(0,0,0,1,s2);
            cout<<ans1 - ans2 <<endl;
        }


   }

}



