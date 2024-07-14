//Intermediary
//Young kid on the block
//AIAsif try's Continuing the journey
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define endl "\n"
#define inf 1000000000000000000
#define int long long int
#define ordered_set tree< int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>

int dp[10][2][82][82];

int k;

string num;

int f(int pos,int tight, int reminder,int sum)
{
        if(pos == num.size())
        {
                return (reminder == 0) && (sum == 0);
        }
        if(dp[pos][tight][reminder][sum]!=-1)
        {
                return dp[pos][tight][reminder][sum];
        }

        int ans = 0;

        for(int i = 0; i <= ((tight)? (num[pos]-'0') : 9); i++)
        {
                ans += f(pos+1, (tight && i==num[pos]-'0'), (reminder*10 + i)%k, (sum+i)%k);
        }

        return dp[pos][tight][reminder][sum] = ans;
}
    
int32_t main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        int t;
        cin>>t;
        for(int tt = 1; tt<=t;tt++)
        {
                int a,b;
                cin>>a>>b>>k;

                memset(dp, -1, sizeof(dp));

                num = to_string(b);

                int ans = f(0,1,0,0);

                num = to_string(a-1);

                memset(dp, -1, sizeof(dp));

                ans -= f(0,1,0,0);

                cout<<"Case "<<tt<<": "<<ans<<endl;
        }

}
