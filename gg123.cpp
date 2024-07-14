#include<bits/stdc++.h>
using namespace std;

int numbers(pair<int, int >  x , int ind , vector<pair<int, int> > &add  )
{
    if(binary_search(add.begin() + ind , add.end(), x))
    {
        int l = lower_bound(add.begin() + ind , add.end(), x) - add.begin();
        int u = upper_bound(add.begin() + ind , add.end(), x) - add.begin();
        return u-l;
    }
    else{
        return 0 ; 
    }
}

int main()
{
    int test;
    cin>> test; 
    while(test--)
    {
        int n , x , y ;
        cin >> n >> x >> y ; 
        vector<pair<int, int> > add , sub ; 

        for(int i = 0; i< n; i++)
        {
            int a ; 
            cin >> a ; 
            add.push_back({a%x , a%y});
        }
      
        sort(add.begin() , add.end());
       
       
        long long  ans = 0;
        for(int i = 0; i< n ; i++)
        {
            int number = add[i].first;
            pair<int, int >  req = {x-number  , add[i].second} ; 
            if(number == 0)
            {
                ans += numbers({number , add[i].second} , i+1 , add);
            }
            else 
            {
                ans+= numbers(req , i+1  , add );
            }
        }
        cout<< ans<<endl;
    }
}