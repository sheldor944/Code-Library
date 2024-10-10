#include<bits/stdc++.h>
using namespace std; 

const int N = 505, inf = 1e8 ; 

int a [N];
int dp[N][N];
int dp2[N]; 
int n ;

int f(int l, int r){
    

    if(l+1 == r){
        return dp[l][r] = a[l];
    }
    if(dp[l][r] != 0){
        return dp[l][r]; 
    }
    dp[l][r] = -1; 
    for(int mid = l+1 ; mid < r ; mid++){
        int leftVal = f(l,mid); 
        int rightVal = f(mid,r); 
        if(leftVal > 0 and leftVal == rightVal){
            dp[l][r] = leftVal+1 ; 
        }
    }
    return dp[l][r]; 
}

int solve(){
    for(int i = 0 ; i <=n ; i++){
        dp2[i] = inf; 
    }
    dp2[0] = 0 ; 
    // cout<<"here\n"; 
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1; j <=n ; j++){
            if(f(i,j) > 0){
                dp2[j] = min(dp2[j], dp2[i]+ 1); 
            }
        }
    }
    return dp2[n]; 
}

int main()
{
    int test = 1,tc=1  ; 
    // cin >> test; 
    cin >> n ; 
    for(int i = 0 ; i < n ; i++){
        cin >> a[i]; 
    }
    // cout<<"input nise\n";
    // memset(dp, -1, sizeof(dp)); 
   
    cout<<solve()<<endl;
}