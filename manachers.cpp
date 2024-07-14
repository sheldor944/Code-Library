#include<bits/stdc++.h>
using namespace std;

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}


int main()
{
    int test ; 
    cin>> test; 
    while(test--)
    {
        string s ; 
        cin>> s ; 
        if(s.size()&1 == 0)
        {
            s+= "#";
        }
        vector<int> v = manacher_odd(s);
        for(int i = 0 ; i< v.size() ; i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}