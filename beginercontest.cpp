#include <bits/stdc++.h>
using namespace std;

int search(int num, vector<int> &v, int start)
{
    int lo = start, hi = v.size() - 1;
    int ans = -1;
    if (lo > hi)
    {
        return ans;
    }
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (v[mid] < num)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
            ans = mid;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;

    while (test--)
    {
        int a, b, c;
        cin >> a;
        vector<int> x, y, z;
        for (int i = 0; i < a; +i++)
        {
            int p;
            cin >> p;
            x.push_back(p);
        }
        cin >> b;

        for (int i = 0; i < b; +i++)
        {
            int p;
            cin >> p;
            y.push_back(p);
        }
        cin >> c;

        for (int i = 0; i < c; +i++)
        {
            int p;
            cin >> p;
            z.push_back(p);
        }
        int cnt = 0;
        int bPos=-1;
        for (int i = 0; i < a; i++)
        {
            int numA = x[i];
            int flag= 0 ; 
            // cout<< numA<<endl;

            int pos2 = search(numA, y, i);
            
            // cout<<pos2<<" num "<< y[pos2] <<endl;
            if (pos2 != -1 )
            {
                for (int j = pos2; j < b; j++)
                {
                    int numB = y[j];
                    int pos3 = search(numB, z, j);
                    if (pos3 != -1)
                    {
                        cnt+= (c-pos3);
                        // cout<< i <<" "<< j <<" "<<pos3<<" "<<cnt<<endl;
                    }
                    else
                    {
                        bPos = j;
                        flag = 1 ; 
                        break;
                    }
                }
            }
            else{
                break;
            }
        }
        cout << cnt << endl;
    }
}