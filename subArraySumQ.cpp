#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll const MAXN = 2e5 + 123;

struct node
{
    ll prefix, suffix, sum, ans;
};

node tree[4 * MAXN];
ll n, q;

void build(ll arr[], ll v, ll l, ll r)
{
    if (l == r)
    {
        tree[v].prefix = arr[l];
        tree[v].suffix = arr[l];
        tree[v].sum = arr[l];
        tree[v].ans = arr[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(arr, 2 * v, l, mid);
    build(arr, 2 * v + 1, mid + 1, r);

    tree[v].prefix = max(tree[2 * v].prefix, tree[2 * v].sum + tree[2 * v + 1].prefix);
    tree[v].suffix = max(tree[2 * v + 1].suffix, tree[2 * v].suffix + tree[2 * v + 1].sum);
    tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;
    tree[v].ans = max(tree[2 * v].ans, max(tree[2 * v + 1].ans, tree[2 * v].suffix + tree[2 * v + 1].prefix));
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val)
{
    if (tl == tr)
    {
        tree[v] = {new_val, new_val, new_val,new_val};
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        tree[v].prefix = max(tree[2 * v].prefix, tree[2 * v].sum + tree[2 * v + 1].prefix);
        tree[v].suffix = max(tree[2 * v + 1].suffix, tree[2 * v].suffix + tree[2 * v + 1].sum);
        tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;
        tree[v].ans = max(tree[2 * v].ans, max(tree[2 * v + 1].ans, tree[2 * v].suffix + tree[2 * v + 1].prefix));
    }
}

int main()
{
    cin >> n >> q;
    ll arr[n + 2];
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    build(arr, 1, 1, n);
    for (ll i = 0; i < q; i++)
    {
        ll pos, val;
        cin >> pos >> val;
        update(1, 1, n, pos, val);
        ll mx = max(tree[1].prefix, max(tree[1].suffix, tree[1].sum));
        cout << max(0LL,tree[1].ans) << endl;
    }
}