#include<bits/stdc++.h>
using namespace std;

int main()
{
    int  n ; 
    cin >> n ; 
    vector<int> v(n+1 , 0 ) , a(n*n +1 , 0 ),cnt(n+1,0);
    for(int i = 1 ; i<= n ; i++)
    {
        int x ; 
        cin >> x ; 
        v[i]= x;
    }
    int flag = 0 ; 
    for(int i = 1 ; i<= n ; i++)
    {
        int idx = v[i];
        int number = i;
        while(number-- )
        {
            if(a[idx]==0)
            {
                a[idx]=i;
                cnt[i]++;
                idx--;
                
            }
            else{
                flag = 1 ; 
                break;
            }
        }
        if(flag){
            break;
        }
    }
    if(flag){
        cout<<"NO";
    }
    else{
        cout<<"YES\n";
        int idx = 1 ; 
        for(int i = 1 ; i<= n*n ; i++)
        {
           if(a[i]==0)
           {
            if(cnt[idx]!=n)
            {
                a[i]=idx;
            }
            else{
                idx++;
            }
           }
        }
        for(int i = 1; i<= n*n ;i++)
        {
            cout<<a[i]<<" "; 
        }
    }
}
