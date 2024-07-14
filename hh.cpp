#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> adjList[26];

bool compare(const vector<int>& a, const vector<int>& b) {
    return a.size() < b.size();
}

int main()
{
    ll test; cin>> test ; 
    while(test--)
    {
        string s; cin >> s ; 
        for(int i = 0; i< s.size() ; i++)
        {
            adjList[s[i]-'a'].push_back(i);
        }   
        sort(adjList, adjList + 26, compare);
        int ans = 0 ; 
        for(int i = 0 ; i< 26 ; i++)
        {
            if(adjList[i].size() >= 2 )
            {
                // cout<<"len is "<<adjList[i].size()<<endl;
                int len = 1;
                int mx = -1 ; 
                int last = adjList[i][0]; 
                for(int j = 1 ; j< adjList[i].size() ; j++)
                {
                    if(adjList[i][j] == last+1 )
                    {
                        
                        len++ ; 
                    }
                    else{
                        // last = adjList[i][j];
                        len = 1 ; 
                    }
                    last = adjList[i][j];
                    mx = max(len , mx );
                }
                cout<<"for "<<char('a'+i)<<": ";
                cout<<mx<<endl;

            }
            // cout<<adjList[i].size()<<endl;
        }
       
        
    }
}