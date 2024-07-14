#include <bits/stdc++.h>
using namespace std;

vector<long long> prime;
long long matrix[101][101];

int main()
{
    long long n , d , p ; 
    cin >> n >> d >> p ; 
    vector<long long > f ; 
    for(long long i = 0; i<n ;i++)
    {
        long long x; 
        cin >>x ; 
        f.push_back(x);
    }
    sort(f.begin() , f.end());
    long long idx = 0 , cnt = 0 ,ans= 0; 
    for(long long i = n-1 ; i >=0 ; i--)
    {
        cnt+= f[i];
        idx++ ; 
        if(idx==d)
        {
            if(cnt> p)
            {
                ans+= p ;
                cnt=0 ; 
                idx=0;
            }
            else{
                ans+= cnt;
                cnt=0 ; 
                idx=0;
            }
        }
    }
    long long rest = 0 ; 
    for(long long i = 0 ; i<=d-idx ; i++)
    {
        rest+= f[i];
    }
    if(rest>d)
    {
        ans+=d;
    }
    else{
        ans+= rest;
    }
    cout<<ans<<endl;
    
}