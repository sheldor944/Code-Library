#include<bits/stdc++.h>
using namespace std;

#define ll long long
 int n ;

int binarySearch(int u , int lo , int hi , int red , vector<int> &pref )
{
    int res = -1 ; 
    int l = lo ;
    while(lo < hi)
    {
        int mid = (lo+hi)/2 ; 
        int len = mid - l + 1;
        int ans = pref[mid] * u - red -( ((len -1) * (len))/2);
        int right = INT_MAX;
        if(mid +1 <n) right = pref[mid+1] * u - red - (((len * (len-1)))/2);
        int left = INT_MIN;
        if(mid-1 > 2) left= pref[mid-1] * u - red - ((len-)/2);
        if(mid > left && mid > right)
        {
            res = mid ;
            break ;  
        }
        else if(mid>=left && mid > right )
        {
            hi = mid-1 ; 
        }
        else if (left< mid & mid <= right)
        {
            lo = mid +1; 
        }
        else if(left >= mid && mid >= right )
        {
            hi = mid -1; 
        }

    }
    if(res == -1) res = l ;
    return res ;
}



int main()
{
    int test ; 
    cin >> test ; 
    while(test--)
    {
       cin >> n ; 
       vector<int> v , pref(n+1 , 0 );
       for(int i = 0 ; i< n ; i++)
       {
            int x ; cin >> x ; 
            v.push_back(x); 
            pref[i+1] += pref[i] + x;
       }
    //    for(int i : pref){
    //     // cout<<i<<" ";
    //    }
    //    cout<<endl;
       int q ; 
       cin >> q; 
       while(q--)
       {
            int l , u ; 
            cin >> l >> u  ;
            int reduction = pref[l-1] * u ; 
            cout<<binarySearch(u,l,n,reduction, pref)<<" ";
       }
        
    }
}