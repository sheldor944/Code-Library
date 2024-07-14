#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
//  https://codeforces.com/gym/100886/problem/G


#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x << " is " << x << endl
#else
#define dbg(x)
#endif
 
const int MOD = 1e9 + 7 ; 
const int N = 3e5 + 123; 
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
string a , b ;

// dp state position, reminder, tight, isPreviousAllZero, isThePreviousOdd

int dp[20][2][2];

int number ; 

int digit_mul(int n)
{
	string s = to_string(n);
	int mul = 1;
	for(int i=0;i<s.size();i++)
	{
		mul *= (s[i] - '0');
	}
 
	return mul;
}


int mul(int a)
{
    int res = 1 ; 
    while(a)
    {
        res *= (a%10);
        a/= 10 ; 
    }
    return res ; 
}

int digitMul(int a, int b )
{
    int ansA = mul(a);
    int ansB = mul(b);
    return ( ansA>= ansB);
}

int power(int num )
{
    int res = 1 ; 
    while(num){
        res *= 10;
        num--;
    }
    return res;
}


int f(int pos , int lowerTight, int upperTight)
{
    if(pos == b.size())
    {
        // dbg("hit");
        return 0;
    }

    if(dp[pos][lowerTight][upperTight] != -1) return dp[pos][lowerTight][upperTight];

    int res = 0 ; 

    for(int i = (lowerTight ?  a[pos]-'0' : 0) ; i <= (upperTight ? b[pos]-'0' : 9) ; i++ )
    {
        int place = b.size()-pos-1;
        // dbg(i);
        // dbg(place);
        // dbg(place);
        int newRes = power(place)*i + f(pos+1, (lowerTight && (a[pos]-'0') == i) ,(upperTight  and i== (b[pos]-'0')) ) ;
        // if(digitMul(newRes, res))
        // {
        //     res = newRes ; 
        // }
        // dbg(newRes);
        dbg(newRes);
        dbg(res);
        if(digit_mul(newRes) >= digit_mul(res)){
            res = newRes;
        }
       
    }


    return dp[pos][lowerTight][upperTight] = res ; 
}


 
int32_t main()
{
    cin >> a >> b ; 
    for(int i = a.size() ; i < b.size(); i++)
    {
        a = "0"+ a;
    }
    dbg(a);
    dbg(b);
    memset(dp, -1 , sizeof(dp));
    cout<< f(0,1,1)<<endl;
 
}



