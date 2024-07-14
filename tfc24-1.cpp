#include<bits/stdc++.h>
using namespace std;

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);

    int test ; 
    cin >> test ; 
   
    while(test--){
        int n  , k , x ; 
        cin >> n >> k >> x ; 
        vector<int> v , pref(n+1,0); 
        for(int i = 0 ; i<n ; i++)
        {
            int a ; 
            cin >> a ; 
            v.push_back(a);
            pref[i]=a;
        }
        for(int i = 1 ; i< n ; i++)
        {
            pref[i]+= pref[i-1];
        }
        int p = n ; 
        for(int i = n-1 ; i >= n-k ; i--)
        {
            int reduction = pref[i-1] - pref[i-x-1 >=0 ? i-x-1 : n] ; 
            int prev = pref[i-1];
            int beforePrev =  pref[i-x-1 >=0 ? i-x-1 : n]; 
            // cout<< prev <<" "<<beforePrev<<endl;
            int rest = pref[(i-x-1) >=0 ? i-x-1 : n];
            
            // cout<< rest<<"  rest : reduction "<< reduction<<endl;
            if(rest < reduction){
                p=i; 
            }
            
        }
        // cout<< p << endl;
        for(int i = p-1 ; i >=((p-x)>0 ? p-x : 0 ); i--)
        {
            v[i]*= -1 ; 
        }
        int sum = 0 ; 
        for(int i = 0 ; i< p ; i++){
            sum+= v[i];
        }
        cout<<sum <<endl;
        

    }
   

}