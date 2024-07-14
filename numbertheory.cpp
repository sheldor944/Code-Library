#include<bits/stdc++.h>
using namespace std;

int n , k ; 

void solve(vector<int>&dp , vector<int>&v , int num)
{
   for(int i = 1 ; i<=n ; i++)
   {
        dp[i]= 0; 
        for(auto u : v){
            if(i-u >=0){
                if(dp[i-u]==0)dp[i]=1;
            }
        }
        if(dp[i])cout<<"W";
        else cout<<"L";
   }
   cout<<endl;
}

int main()
{
    int test ; 
    cin>> test ; 
    while(test--){
        int n ; 
        cin >> n ; 
        vector<int> v ; 
        int xr = 0 ; 
        for(int i = 0 ; i<n ; i++)
        {
            int x ; 
            cin >> x ; 
            x  = x%4;
            xr^=x;
        }
        if(xr)cout<<"first\n";
        else{
            cout<<"second\n";
        }

    }
    

}