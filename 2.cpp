#include<bits/stdc++.h>
using namespace std;

#define int long long


#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x << " is " << x << endl
#else
#define dbg(x)
#endif


const int N = 5e5 +123;
int checker[N];
int last = 0 ; 
int calculate(){
    for(int i = last ; i < N ; i++)
    {
        if(checker[i]==0)
        {
            last = i ; 
            return i ; 
        }
    }
}


int32_t main()
{
    int test ; cin>> test; 
    while(test--)
    {
        int n ; cin >> n ; 
       
        vector<int> v ; 
        set<int> st;
        for(int i =0 ; i < n ; i++)
        {
            int x ;cin >> x ; 
            st.insert(i);
            v.push_back(x);
        }
        // st.insert(5);
        int mex = 0 ; 
        vector<int> ans ; 
        mex = calculate();

        for(int i  = 0 ; i< n ; i++)
        {
            // cout<<"for i mex is "<<i <<" "<<mex<<endl;
            int curr = last ; 
            last ++ ; 
            int newMex = calculate(); 
            if(st.find(newMex - v[i]) != st.end())
            {
                // cout<<i<<" "<<mex +1 -v[i]<<endl;
                last = curr;
                ans.push_back(mex);
                st.erase(mex);
                checker[mex]=1;
               
            }
            else{
                last = curr;
                int y = mex - v[i];
                ans.push_back(y);
                checker[y]=1;
                st.erase(y);

            }
            mex = calculate();
        }
        // for(auto u : st){
        //     ans.push_back(u);
        // }
        for(auto u : ans){
            cout<<u<<" ";
        }
        for(int i = 0 ; i<= n ; i++)
        {
            checker[i]=0;
            last = 0 ; 
        }
        cout<<endl;
    }
}