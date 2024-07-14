#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test ;
    cin>> test ; 
    while(test--)
    {
        int n , m ; 
        cin >> n >> m ; 
        string temp , s="#" ; 
        cin>> temp ; 
        s+= temp ; 
        vector<int> right_one(n+2) , left_zero(n+2);
        int pos = 0 ; 
        for(int i= 1 ; i<= n ; i++)
        {
            if(s[i]=='0')pos= i ; 
            left_zero[i]=pos;
        }
        pos = n+1 ; 
        for(int i = n ; i>0 ; i--)
        {
            if(s[i]=='1')pos = i;
            right_one[i]=pos ; 
        }
        vector<int> prefix(n+3);
        for(int i = 1 ; i<= n ; i++)
        {
            prefix[i]+= prefix[i-1]+(s[i]-48);
        }
        for(int i = 1 ; i<= n ; i++)
        {
            cout<<left_zero[i];
        }
        cout<<endl;
        for(int i = 1 ; i<= n ; i++)
        {
            cout<<right_one[i];
        }
        cout<<endl;
        set<pair<int,int>> st ; 
        for(int i = 0 ; i< m ; i++)
        {
            int l , r ; 
            cin>> l>> r ; 
            int ones = (prefix[r] - prefix[l]) + (s[l]-48);
            if(ones == (r-l+1))
            {
                //sorted
                continue;
            }
            int part = r - ones  ; 
            if(prefix[l] == prefix[part]){
                //sorted 
                continue;
            }
            st.insert({left_zero[l],right_one[r]});
        }
        cout<<st.size()<<endl;

    }
}