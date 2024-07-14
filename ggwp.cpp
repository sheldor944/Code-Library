#include <bits./stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        int flag = 0;
        int pref = 0, mx = -1, minus = 0, plus = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (pref + a == n)
            {
                cout << "YES\n";
                flag = 1;
                break;
            }
            else if ((a - minus >= 0) && plus >= (n - a))
            {
                cout << "MAYBE\n";
                flag = 1;
                break;
            }
            if (s[i] == '+')
            {
                pref++;
                plus++;
            }
            else
            {
                pref--;
                minus++;
            }
        }
        if (flag)
            continue;
        if (pref + a == n)
        {
            cout << "YES\n";
            flag = 1;
            
        }
        else if ((a - minus >= 0) && plus >= (n - a))
        {
            cout << "MAYBE\n";
            flag = 1;
            
        }
        if (!flag)
        {
            cout << "NO\n";
        }
    }
}