#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string s = "#", t;
        cin >> t;
        s += t;
        int lastZero = -1, lastOne = -1, lastVar = -1;
        int firstZero = -1, firstOne = -1, firstVar = -1;
        long long ans = 0, cnt = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                if (firstZero == -1)
                {
                    if (firstOne == -1)
                    {
                        firstZero = i;
                        cnt++;
                        ans += cnt;
                    }
                    else if (firstOne & 1 == i & 1)
                    {
                        if (s[i - 1] == '?')
                        {
                            firstZero = i;

                            cnt = 2;
                            ans += 2;
                        }
                        else
                        {
                            firstZero = i;
                            cnt = 1;
                            ans += cnt;
                        }
                    }
                    else
                    {
                        firstZero = i;
                        cnt++;
                        ans += cnt;
                    }
                }
                else if ((firstZero & 1) == (i & 1))
                {
                    lastZero = i;
                    cnt++;
                    ans += cnt;
                }
                else
                {

                    if (s[i - 1] != s[i])
                    {
                        
                        if (lastVar != -1)
                        {
                            cnt = i - lastVar + 1;
                            ans += cnt;
                            
                        }
                    }
                    else if (s[i - 1] == '?')
                    {
                        cnt = 2;
                        ans += cnt;
                    }
                    else
                    {
                        cnt = 1;
                        ans += cnt;
                    }
                }
            }
            else if (s[i] == '1')
            {
                if (firstOne == -1)
                {
                    if (firstZero == -1)
                    {
                        firstOne = i;
                        cnt++;
                        ans += cnt;
                    }
                    else if (firstZero & 1 == i & 1)
                    {
                        if (s[i - 1] == '?')
                        {
                            firstOne = i;

                            cnt = 2;
                            ans += 2;
                        }
                        else
                        {
                            firstOne = i;
                            cnt = 1;
                            ans += cnt;
                        }
                    }
                    else
                    {
                        firstOne = i;
                        cnt++;
                        ans += cnt;
                    }
                }
                else if ((firstOne & 1) == (i & 1))
                {
                    lastOne = i;
                    cnt++;
                    ans += cnt;
                }
                else
                {

                    if (s[i - 1] != s[i])
                    {
                        
                        if (lastVar != -1)
                        {
                            cnt = i - lastVar + 1;
                            ans += cnt;
                            
                        }
                    }
                    else if (s[i - 1] == '?')
                    {
                        cnt = 2;
                        ans += cnt;
                    }
                    else
                    {
                        cnt = 1;
                        ans += cnt;
                    }
                }
            }
            else if (s[i] == '?')
            {
                if (firstVar == -1)
                {
                    firstVar = i;
                    lastVar = i ; 
                    cnt++;
                    ans += cnt;
                }
                else
                {
                    cnt++;
                    ans += cnt;
                    lastVar = i;
                }
            }
            cout << i << " " << ans << " " << cnt << endl;
        }
        cout << ans << endl;
    }
}