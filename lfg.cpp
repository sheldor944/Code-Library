#include<bits/stdc++.h>
using namespace std;
int n, m;
string st = "narek";
int dp[1000][5];

int solve(string s[], int idx, int id) {
    int f = id;
    if(idx == n) {
        return -id;
    }
    if(dp[idx][id] != INT_MIN) {
        return dp[idx][id];
    }
    int sc1 = 0, sc2 = 0;
    for(int i = 0; i < m; i++) {
        if(s[idx][i] == st[id]) {
            id++;
            if(id == 5) {
                id = 0;
                sc1+=5;
            }
        }else if(find(st.begin(), st.end(), s[idx][i]) != st.end()) {
            sc2++;
        }
    }
    int ans = max(solve(s, idx+1, f), sc1 - sc2 + solve(s, idx+1, id));
    return dp[idx][f] = ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    cin >> tt;
    while(tt--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 5; j++) {
                dp[i][j] = INT_MIN;
            }
        }
        string s[n];
        for(int i = 0; i < n; i++) {
            cin >> s[i];
        }
        cout << solve(s, 0, 0) << "\n";
    }
    return 0;
}