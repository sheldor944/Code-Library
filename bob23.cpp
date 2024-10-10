#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ; cin >> n ; 
    vector<int> radi, gg; 
    radi.push_back(-1);
    gg.push_back(0);
    for(int i = 1; i<= n; i++){
        int x ; cin >> x; 
        radi.push_back(x);
        gg.push_back(x);
    }
    sort(radi.begin(), radi.end());
    int q ; cin >> q ; 
    n++;
    while(q--){
        int i, k ; cin >> i >> k ; 
        int minimum = n - i + 1 ; 
        
        // if( k < minimum){
        //     cout<<"0f\n";
        //     continue;
        // }
        double r1 = radi[n-k];
        double r2 = gg[i];
        cout<<r1<<" "<<r2<<endl;
        if(r1 == -1  and k+1 == n and r2 == radi[1]) {
            cout<<"1.00000000000\n";
            continue;
        }
        else if(r1 == -1){
            cout<<"0.000000000\n";
            continue;

        }
        double theta = acos(r1/r2);
        // cout<<theta<<endl;
        
        double prop =  (theta/ M_PI); 
        prop = prop*2.0;
        cout<<fixed<<setprecision(9)<<prop<<endl;

    }
}