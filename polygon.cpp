#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ull unsigned long long

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
        int n ,x , y; cin >> n >> x >> y ; 
       
        vector<int> v ; 
        set<int> gg;
 
        for(int i =0 ; i < x ; i++)
        {
            int xx ;cin >> xx ; 
            gg.insert(xx);
            v.push_back(xx);
        }
        int ans = 0 ; 
        sort(v.begin() , v.end());
        int rem = 0 , cnt=0 ; 
        set<int> st;
        for(auto it = gg.begin() ; it != gg.end() ; it++)
        {
            int i = *it;
            // cout<<"i is "<<i<<endl;
            if(i < n-1){
                if(gg.find(i) != gg.end()){
                    if(gg.find(i+2) != gg.end())
                    {
                        ans++;
                        st.insert(i);
                        st.insert(i+2);
                        it = gg.find(i+2);
                        it--;
                    }
                    else{
                        st.insert(i);
                    }
                }
                // cout<<"here i and ans "<<i<<" "<<ans<<endl;
            }
            else{
                if(gg.find(i) != gg.end())
                {
                    if(gg.find( (i+2) % n) != gg.end()  && st.find((i+1) % n ) == st.end())
                    {
                        ans++;
                        st.insert(i);
                        st.insert((i+2) %n);
                        // cout<<i <<" "<<i+2<<endl;
                       it = gg.find(i+2);
                        it--;
                    }
                    else{
                        st.insert(i);
                    }
                    
                }
            }
        }
        dbg(ans);
        dbg(st.size());
        vector<int> yy ; 
        int extra = 0 ; 
        int sum  = 0 ; 
        for(auto it = st.begin() ; it != st.end() ; it++)
        {
            int node = *it ; 
            auto temp = std::next(it);

            int tempNode ; 
            if(temp == st.end())
            {
                
                // break;
                int start = *st.begin();
                int gap = n - node +start ;

                // cout<<"gap is "<<gap <<endl;
                dbg(gap);
                extra = (gap - 2) /2; 
                dbg(extra);
                sum+=extra;
                 yy.push_back(extra);
                 break;

            }else{
                tempNode = *temp ; 
                extra = (tempNode-node -1  )/2;
            yy.push_back(extra);
            }
            // cout<<node<<" "<<tempNode<<endl;
            // cout<<"extra is "<<extra<<endl;
            dbg(node);dbg(tempNode);
            dbg(extra);
                sum+=extra;

           

        } 
        sort(yy.rbegin() , yy.rend());
        // cout<<"here"<<endl;
        int ex = 0 ;
        for(int i = 0 ; i< y  ; i++)
        {
            ex+= yy[i];
        }
        // cout<< ex <<endl;
        int total = ex + ans ; 
        // cout<<total<<endl;
        int nodes = st.size()+ ex ; 
        // cout<<nodes<<endl;
        total += (st.size() + ex -2);
        // cout<<ans<<endl;
        cout<< total<<endl;       
    }
}