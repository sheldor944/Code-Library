#include <bits/stdc++.h>
using namespace std;

struct info
{
    long long pref, sum;
};

const long long MAXN = 2e5 + 12;

long long n, q;
info tree[4 * MAXN];
long long arr[MAXN];

void build(long long arr[], long long v, long long l, long long r)
{
    if (l == r)
    {
        tree[v].pref = arr[l];
        tree[v].sum = arr[l];
    }
    else
    {
        long long mid = (l + r) / 2;
        build(arr, 2 * v, l, mid);
        build(arr, 2 * v + 1, mid + 1, r);
        tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;
        tree[v].pref = max(tree[2 * v].pref, tree[2 * v].sum + tree[2 * v + 1].pref);
    }
}

void update(long long v, long long tl, long long tr, long long pos, long long new_val)
{
    if (tl == tr)
    {
        tree[v].pref = new_val;
        tree[v].sum = new_val;
    }
    else
    {
        long long tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;
        tree[v].pref = max(tree[2 * v].pref, tree[2 * v].sum + tree[2 * v + 1].pref);
    }
}

long long query(long long v, long long tl, long long tr, long long l, long long r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
    {
        return tree[v].pref;
    }
    long long tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main()
{
    cin >> n >> q;

    for (long long i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    build(arr, 1, 1, n);
    for (long long i = 0; i < q; i++)
    {

        long long t, a, b;
        cin >> t >> a >> b;
        if (t == 1)
        {
            update(1, 1, n, a, b);
        }
        else
            cout << (query(1, 1, n, a, b) > 0 ? query(1, 1, n, a, b) : 0) << endl;
    }
}