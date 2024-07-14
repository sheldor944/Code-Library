#include<bits/stdc++.h>
using namespace std;

#define int long long


#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x << " is " << x << endl
#else
#define dbg(x)
#endif

const int MOD = 1e9 + 7 ; 
const int N = 3e5 + 123; 
// int dp[N];

int n, k ;


int32_t main()
{
    int test ; cin >> test ; 
    while(test--)
    {
        string s ; cin >> s ; 
        int ans = 0 ;
        // s = "#" + s; 
        priority_queue<int, std::vector<int>, std::greater<int>> pq ; 
        for(int i =0 ;i< s.size() ; i++)
        {
            if(s[i] == '0')
            {
                pq.push(i);
            }
        }
        for(int i = 0 ; i< s.size() ; i++)
        {
            if(s[i] == '1')
            {
                 if(pq.empty()){
                    break ; 
                }
                int next = pq.top();
                int flag = 0 ;  
                while(next< i){
                    pq.pop(); 
                     if(pq.empty()){
                        flag = 1; 
                    break ; 
                }
                    next = pq.top();
                }
                if(flag)
                {
                    break;
                }
                // cout<<i<<" "<<next<<endl;
                ans += ( next - i + 1);

                pq.pop(); 
                if(pq.empty()){
                    break ; 
                }
                s[next] = '1';
            }
        }
        cout<<ans<<endl;

    }
}
