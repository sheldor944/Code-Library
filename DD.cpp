#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 ; 

char parent[30];

char A = 'a';

void make_set(char v) {
    parent[v - A] = v;
}

char find_set(char v) {
    if (v == parent[v - A])
        return v;
    return find_set(parent[v - A ]);
}

void union_sets(char a, char b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        cout<<" parent of this is that "<< b <<" "<<a<<endl;
        parent[b - A ] = a;}
    else{
        parent[b-A] = a;
    }
}

int  main()
{
    int n ; cin >> n ; 
    string s ; cin >> s ; 
    int q ; cin >> q ; 
    map<char, char > mp ;
   
    for(char i = 'a' ; i <= 'z' ; i++)
    {
        make_set(i);
    }
    while(q--)
    {
        char a , b ; 
        cin >> a >> b ; 
        union_sets(b,a);

    }

    for(int i = 0 ; i < n ; i++)
    {
        char ans ;
        ans = find_set(s[i]);
        // if(mp.count(s[i]) <= 0 ){
        //     ans= s[i];
        // }
       cout<<ans;
    }
    cout<<endl;
    
}