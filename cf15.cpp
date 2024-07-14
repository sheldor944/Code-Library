#include <bits/stdc++.h>
using namespace std;

int prev[100000];


int main()
{
    int test;
    cin >> test;
    while (test--)
    {
       int n , m ,d  ; 
       cin>> n >> m >> d; 
       vector<int> s ; 
       int ans = 1 + ( n-1)/d  + m;
       int flag = 0 ; 
    //    cout<< ans<<endl;
       int option = 0 ; 
       for(int i = 0 ; i<m ; i++)
       {
            int x ; 
            cin>> x ; 
            int l = ( (x-1)/d);
            l = (l*d) +1  ; 
            int high = ((x-1)/d); 
            high = (high +1)*d  + 1 ; 
            s.push_back(x);
            if((x-1)%d==0)
            {
                ans--;
                // cout<<"got it \n";
            }
            int right = lower_bound(s.begin() , s.end() , high) - s.begin();
            int left = lower_bound(s.begin() , s.end() , l+1) - s.begin();
            int op = right - left ;
            if(op && flag == 0 ){
                ans--;
                flag = 1 ; 
            }
            option += op ; 
       }
       cout<< ans << " "<<option<<endl;
       

    }
}