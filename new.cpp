#include <bits/stdc++.h>
using namespace std;

#define ll long long

void cl(priority_queue<ll> pq)
{
    while (!pq.empty())
    {
        pq.pop();
    }
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            v.push_back(i);
        }
        ll ans = 0;
        priority_queue<ll> pq;
        for (int i = 0; i < n; i++)
        {

            pq.push(v[i] * (i + 1));
            ans += (v[i] * (i + 1));
            cout << v[i] << " ";
        }
        cout << endl;
        
            cout << endl << ans << " " << pq.top() <<"   "<< ans - pq.top() << endl;
        ll mx = ans - pq.top();
       
         while (!pq.empty())
            {
                pq.pop();
            }
        while (next_permutation(v.begin(), v.end()))
        {
            ans = 0;
            for (int i = 0; i < n; i++)
            {
                ans += (v[i] * (i + 1));
                pq.push(v[i] * (i + 1));

                cout << v[i] << "  ";
            }
            cout<<endl;
            for(int i = 0; i< n ; i++)
            {
                cout<<v[i]*(i+1)<< " ";
            }
            // cout << endl;
            cout << endl << ans << " " << pq.top() <<" "<< ans - pq.top() << endl<<endl;
            mx = max(mx, ans - pq.top());
            while (!pq.empty())
            {
                pq.pop();
            }
           
        }

        cout<<mx<<endl;
    }
}