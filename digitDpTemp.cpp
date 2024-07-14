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



// dp[pos][tight][sum] = total sum of all digits of numbers that can be formed using the remaining `pos to lsb digits` `having already formed (msb to pos) digits and their sum = sum` ` having already formed `msb to pos digits`  sum = sum` .

// pos = index of digit, [from msb to lsb]

// tight = bounded or not..

// sum = msb to pos digits sum


int dp[20][2][180];


int f(int pos, int tight, int sum, string num) // make the num.size() == 20 , by filling left's indices with 0's
{
        if(pos == num.size()) // pos over hoye gese
        {

                return sum;
        }

        if( dp[pos][tight][sum] != -1)
        {
                return dp[pos][tight][sum];
        }

        int ans = 0;

        if (tight)
        {
                for(int i = 0 ; i < (num[pos] - '0') ;i++) // less than last digit
                {
                        ans += f(pos+1, 0, sum+i, num);
                }

                ans += f(pos+1, 1,  sum + (num[pos] - '0'), num); // last digit er jonno tight kore dilam
        }
        else 
        {
                for(int i = 0 ; i < 10 ;  i++) 
                {
                        ans += f(pos+1, 0, sum+i, num);
                }
        }


        return dp[pos][tight][sum] = ans;


}


   
int32_t main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);


        memset(dp, -1, sizeof(dp));

        int ans = f(0,1,0, "155");
        cout<<ans<<endl;


        memset(dp, -1, sizeof(dp));


        ans -= f(0,1,0, "010");


        cout<<ans<<endl;
        for(int i =0 ; i< 180 ; i++)
        {
            cout<<dp[0][0][i]<<" "<<dp[0][1][i]<<endl;
        }

}



// dp[pos][tight][sum] = total number of sum of all digits of numbers which are prime 
// that can be formed using the 
// remaining pos to lsb digits having already formed (msb to pos) digits and their sum = sum `