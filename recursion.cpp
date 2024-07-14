#include<bits/stdc++.h>
using namespace std;
 
// #define int long long
 
 
#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x << " is " << x << endl
#else
#define dbg(x)
#endif
 
const int MOD = 1e9 + 7 ; 
const int N = 3e5 + 2; 
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

// int a, b;
vector<int> va ;
int m , n ; 
int k ;

int t[4*N];

void build(vector<int> &a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] | t[v*2+1];
    }
}

int bitwiseOr(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return bitwiseOr(v*2, tl, tm, l, min(r, tm))
           | bitwiseOr(v*2+1, tm+1, tr, max(l, tm+1), r);
}
 
int32_t main()
{
   int test ; cin>> test ;
   int tc=1 ;  
   while(test--)
   {
       int n ; cin >> n ; 
       int total = 0 ;
    //    va.resize(n);
       for(int i = 0; i < n; i++) {
            int x; 
            cin >> x; 
            total |= x;
            // 
            va.push_back(x);
       }

       int window = 0 ; 
       k = 0 ; 
       int curr =0 ;
       for(int i =0 ; i< n ; i++)
       {
            curr |= va[i];
            if(curr == total )
            {
                k = i+1 ; 
                window = k ; 
                break ; 
            }
       }
       dbg(total);
    //    dbg(window);
       build(va,1, 0, n-1);
       for(int i = 1 ; i < n  and i+window -1 <= n-1  ; i++)
       {  
           int curr = bitwiseOr(1, 0,n-1,i,i+window-1);
           dbg(i);
           dbg(i+window-1);
           dbg(curr);
           while(curr != total){
                window++ ;
                dbg(window);
                dbg(i);
                if(i+window >n ){
                    window = n ;
                    break;
                }
                dbg("here");
                dbg(i);
                curr = bitwiseOr(1, 0,n-1,i,i+window-1);
                dbg(i+window-1);
                dbg(curr);
           }
       }
       cout<<window<<endl;
       va.clear();
       for(int i = 0 ; i <=5*n ; i++)
       {
            t[i]=0; 
       }



   }

}



