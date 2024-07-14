#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        ll ans = 0;
        ll res = -1;
        for (int j = 0; j <= n; j++)
        {
            vector<ll> v;

            for (int i = 1; i <= n - j; i++)
            {
                v.push_back(i);
            }
            for (int i = n; i > n - j; i--)
            {
                v.push_back(i);
            }
            ll mn = -1;
            // priority_queue<ll> pq ;
            for (int i = 0; i < n; i++)
            {
                mn = max(mn, v[i] * (i + 1));
                ans += v[i] * (i + 1);
            }
            res = max(res, ans - mn);
            ans = 0;
        }
        cout << res << endl;
    }
}