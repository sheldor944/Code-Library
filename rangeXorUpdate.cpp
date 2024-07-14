#include<bits/stdc++.h>
using namespace std;

const int MAXN= 2e5 + 12; 

int n , q , tree[4*MAXN] ; 

void build(int arr[] , int v , int l , int r)
{
    if(l == r )
    {
        tree[v] = arr[l];
    }
    else{
        int mid = ( l + r ) / 2 ; 
        build( arr, 2 * v , l , mid ); 
        build( arr , 2*v + 1 , mid +1 , r); 
        tree[v] = max(tree[2*v] , tree[2*v + 1 ]);
    }
}

int query(int v , int l , int r , int val)
{
    if(l == r )
    {
        if( tree[v]>= val)
        {
            return l;
        }
        else{
            return -1 ; 
        }
    }
    if(tree[v] >= val)
    {
        return query(2*v , l , (l+r)/2 , val);
    }
    else{
        return query( 2*v +1 , (l+r)/2 + 1 , r , val) ; 
    }
}


int main()
{
    cin>> n >> q  ; 
    int arr[n+1];
    for(int i = 1 ; i<= n ; i++)
    {
        cin >> arr[i];
    }
    build(arr , 1 , 1 , n );
    for(int i = 0 ; i< q ; i++)
    {
        int a ; 
        cin>> a ; 
        cout<<query(1 , 1 , n , a)<<endl;
    }
   
}