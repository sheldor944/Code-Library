#include <bits/stdc++.h>
using namespace std;

int sub(string one , string two )
{
    int flag = 0 ; 
    for(int i = 0 ; i< two.size() ; i++)
    {
        flag = 0 ;
        for(int j = i ; j < two.size() ; j++)
        {
            if(one[i+j] != two [j])
            {
                flag = 1;
                break ; 
            }
        }
        if( flag == 0 )
        {
            return 1 ; 
        }
    }
    return 0 ; 
}



int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string s, one = "", two = "";
        cin >> s;
        int n = s.size();
        if (n == 1 or s == "()")
        {
            cout << "NO\n";
            continue;
        }
        else
        {
            cout << "YES\n";
        }
        for (int i = 0; i < n; i++)
        {
            one += "(";
        }
        for (int i = 0; i < n; i++)
        {
            one += ")";
        }
        for (int i = 0; i < n; i++)
        {
            two += "()";
        }
        // cout<<s <<" \n"<<one<<" \n"<<two<<endl;
        if(sub(one,s))
        {
            cout<<two<<endl;
        }
        else if(sub(two , s))
        {
            cout<<one<<endl;
        }
    }
}