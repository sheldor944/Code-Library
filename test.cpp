#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define all(v) v.begin(), v.end()
#define ull unsigned long long
#define pb push_back

#ifdef LOCAL
#define dbg(x) cerr << #x << " is " << x << endl;
#else
#define dbg(x)
#endif

const int N = 5005;

ll INF = 1e18;
ll dp[N][N];

void solve() {
    ll n;
    cin >> n;
    for(ll i = 0; i <= n; i++) {
        for(ll j = 0; j <= n; j++) {
            dp[i][j] = INF;
        }
    }
    for(int i = 0; i <= n; i++) dp[0][i] = dp[1][i] = 0;
    for(ll i = 2; i <= n; i++) {
        for(ll j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j - 1];
            if(i - j - 1 >= 0) dp[i][j] = min(dp[i][j], dp[i - j - 1][j - 1] + j * (j + 1) / 2);
            // cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
        }
    }
    ll ans = INF;
    for(ll i = 0; i <= n; i++) ans = min(ans, dp[n][i]);
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;

    // while(t--) {
    //     solve();
    // }
    solve();

    return 0;
}
