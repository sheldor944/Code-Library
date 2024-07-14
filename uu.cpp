#include<bits/stdc++.h>
using namespace std;

#define ll long long



int main()
{
    ll test; cin>> test ; 
    while(test--)
    {
       int l , r ; 
       cin >> l >> r ; 
       vector<int> v ; 
       for(int i = l ; i+1<= r ; i+=2)
       {
            v.push_back(i+1);
            v.push_back(i);
       }
       int flag = 0 ; 
       if((r-l+1) & 1)
       {
        // cout<<"here";
            int st = l ; 
            for(int i = 0 ; i< v.size() ; i++)
            {
                if(__gcd(st,r) == 1 and __gcd(r,v[i]) == 1)
                {
                    v.push_back(r);
                    swap(v[i] , v[v.size()-1]);
                    flag = 1 ; 
                    break;
                }
                st++;
            }
       }
       if( (r-l+1)&1 && !flag){
            cout<<"-1\n";
            continue;
       }
       for(auto u : v){
        cout<<u<<" ";
       }
       cout<<endl;
        
    }
}