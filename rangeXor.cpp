#include<bits/stdc++.h>
using namespace std; 

const int MAXN = 2e5 ; 


int n, t[4*MAXN];

void build (int a[] , int v , int l, int r)
{
    if(l==r)
    {
        t[v]=a[l];
    }
    else{
        int mid = ( l + r) / 2 ; 
        build(a , 2* v , l , mid);
        build(a , 2*v + 1 , mid +1 , r);
        t[v] = t[2*v]^t[2*v + 1];
    }
}

int query(int v , int tl , int tr , int l , int r )
{
    if(l> r )
    {
        return 0 ;
    }
    if(l == tl && r == tr)
    {
        return t[v];
    }
    int mid = (tr + tl )/2;
    return query(2*v , tl , mid , l , min(r , mid )) ^ query(2*v +1 , mid + 1  , tr , max(l , mid+1 ) , r); 
}


int main()
{
    int q ; 
    cin>> n >> q ; 
    int arr[n+1];
    for(int i = 1 ; i<= n ; i++)
    {
        cin >> arr[i];
    }
    build(arr ,1 , 1, n  );
    for(int i = 0 ; i< q ; i++)
    {
        int l , r ; 
        cin>> l >> r ;
        cout<<query(1 , 1, n , l , r )<<endl;
    }
    
}