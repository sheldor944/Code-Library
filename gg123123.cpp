#include<bits/stdc++.h>
using namespace std;
#define ll long long



int  main()
{
    ll  test ; 
    cin >> test ; 
    int N = 2e5 + 10 ;
    
    while(test--)
    {
        int n , k  ; cin >> n >> k ; 
        int odd = (n+1 )/2 ; 
        // cout<<odd<<endl;
        if(k <= odd){
            cout<< (2*k) -1<<endl; ; 
        }
        else{
            k-=odd; 
            // cout<<k<<endl;
            int init = 2 ; 
            while(k)
            {
                int gg = n-init ; 
                // cout<<" gg is "<<gg<<endl;
                gg = gg/(2*init);
                gg++;
                // cout<<"final gg is "<<gg<<" and k is "<<k<<endl;
                if(k <= gg){
                    // cout<<"here"<<endl;
                    ll ans = init + (2*init*(k-1));
                    k=0;
                    cout<<ans<<endl;
                }
                else{
                    init = init*2 ; 
                    k-= gg;
                }
            }
        }
        
    }
}
