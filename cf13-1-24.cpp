#include<bits/stdc++.h>
using namespace  std ; 

void printDivisors(int n, vector<int>& factors) 
{ 
    if(n==2){
        factors.push_back(1);
        factors.push_back(2);

    }
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i) 
                factors.push_back(i); 
  
            else  
                if(i == (n/i)){
                factors.push_back(i); 

                }
                else{
                    factors.push_back(i); 
                    factors.push_back(n/i); 
}
        } 
    } 
    sort(factors.begin() , factors.end());
    // for(auto i : factors)
    // {
    //     cout<<i<<endl;    
    // }
} 
int main()
{
    int test ; 
    cin >> test ; 
    while(test--)
    {
        int n ; 
        cin >> n ; 
        vector<int> v ; 
        for(int i = 0 ; i< n ; i++)
        {
            int x ; 
            cin >> x ; 
            v.push_back(x);
        }
        int gcd = v[0];
        for(int i = 0 ; i< n ; i++)
        {
            gcd = __gcd(gcd, v[i]);
        }
        // cout<<gcd<<endl;
        if(n==1){
            cout<<1<<endl;
            continue;

        }
        if(gcd==1)
        {
            int ans = 1 ; 
            vector<int> factors ; 
            printDivisors(n, factors);
            // cout<<factors.size()<<endl;
            for(int i = 0 ; i < factors.size()-1 ; i++)
            {
                int flag = 0 ; 
                vector<int> check(n+1 , 0 );
                // cout<<ans<<" ans is and  factor is "<< factors[i]<<endl<<endl;
                for(int j = 1 ; j < n ; j++)
                {
                    int start = v[j] ;
                  
                    if(check[j])continue;

                    //   cout<< j<<" -> start is "<<start <<"\n";
                    for(int k = j ; k < n ; k+=factors[i])
                    {
                        // cout<<"-- "<< k <<" "<<v[k] <<endl;
                        check[k]=1;
                        if((v[k]&1) != (start&1))
                        {
                            // cout<<"hit\n";
                            flag = 1; 
                            break;
                        }
                    }
                    if(flag){
                        break;
                    }
                }
                if(flag == 0 ){
                    ans++; 
                }
            }
            cout<<ans<<endl;
            
        }
        else{
            vector<int> factors; 
            printDivisors(n , factors);
            cout<<factors.size()<<endl;
        }
    }
}