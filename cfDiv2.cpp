#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test ; 
    cin >> test ;
    while(test--)
    {
        int n; 
        cin >> n ; 
        int arr[n+1];
        int sum = 0 , one = 0 ;  
        for(int i = 0 ; i< n ; i++)
        {
            cin >> arr[i];
            if(arr[i]==1){
                one++;
            }
            sum += arr[i];
        }
        int withoutOne = sum - one ; 
        if(one== 0 && n!=1)
        {
            cout<<"YES\n";
        }
        else if( n== 1 )
        {
            cout<<"NO\n";
        }
        else if ( withoutOne < 2*one)
        {
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }

    }
}