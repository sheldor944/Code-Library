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
const int N = 5e5 + 10 ; 
 
int fact[N], invFact[N];
 
int pwr(int x, int y)
{
  if(y==0)return 1;
  if(y%2==0)
  {
    int tmp = pwr(x, y/2);
    return tmp*tmp%M;
  }
  else{
    int tmp = pwr(x, y-1);
    return tmp*x%M;
  }
}
 
void precalc()
{
  fact[0] = 1;
  for(int i=1;i<N;i++)fact[i] = i*fact[i-1]%M;
  invFact[N-1] = pwr(fact[N-1], M-2);
  for(int i=N-2;i>=0;i--)invFact[i] = invFact[i+1]*(i+1)%M;
}
 
int ncr(int n, int r)
{

  int ans = fact[n];
//   cout<<ans<<endl;
  ans*=invFact[r];
//   cout<<ans<<endl;

  ans%=M;
//   cout<<ans<<endl/;

  ans*=invFact[n-r];
//   cout<<ans<<endl;

  ans%=M;
//   cout<<ans<<endl;

  return ans;
}

