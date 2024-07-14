#include<bits/stdc++.h>
using namespace std;
 
const int K = 22, N = 1<<K;
int ans[N];
int a[N];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin>>n;
    fill(ans, ans+N, -1);
 
    for (int i=0; i<n; i++) {
        cin>>a[i];
        ans[a[i]] = a[i];
    }
 
    for (int i=0; i<K; i++)
        for (int mask=0; mask<N; mask++)
            if (ans[mask] == -1 && (mask & (1<<i)) && ans[mask^(1<<i)] != -1)
                ans[mask] = ans[mask^(1<<i)];
 
    for (int i=0; i<n; i++)
        cout<<ans[N-1-a[i]]<<" ";
}