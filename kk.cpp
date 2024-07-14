#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 ; 


vector<char> adjList[30];

char leaf ;
void dfs(char u , char p)
{
    for(auto v : adjList[u-'a'])
    {
        if(v == p)continue;
        dfs(v, u);
    }
    if(p != '#' and adjList[u-'a'].size() == 1)
    {
        leaf = u ; 
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
        mp[i] = i  ;
    }
    while(q--)
    {
        char a , b ; 
        cin >> a >> b ;
        adjList[a-'a'].push_back(b); 
    }

    for(int i = 0 ; i < n ; i++)
    {
        char ans  = s[i];
        leaf = s[i];
        // for(int i = 0 ; i< 26 ; i++)
        // {
        //     ans = mp[ans];
        // }
      
        // if(mp.count(s[i]) <= 0 ){
        //     ans= s[i];
        // }
        dfs(leaf, '#');

       cout<<leaf;
    }
    cout<<endl;
    
}