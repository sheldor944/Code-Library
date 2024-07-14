#include<bits/stdc++.h> 
using namespace std;

using ll = long long ;
int inf = INT_MAX;


int result(int k , vector<int>& arr)
{
    int total = 0 ; 
    for(int i = 0; i< arr.size(); i++)
    {
         if (arr[i] == 0 || k == 0){
            continue;
        }
        ll x = arr[i] / k;
        ll l = arr[i] % k;
        ll r = k - l;
        ll L = (x + 1) * l, R = x * r;
        total += ( R * L + (R - x) * R / 2 + L * (L - x - 1) / 2);
    }
    cout<<"total :"<<total<<endl; 
    return total;
}

int ternary(int n , int b , int x , vector<int>& arr)
{
    int lo = 1, hi = n;
    int test = 100; 
    ll res =0; 
    while(test--)
    {
        int k = (lo + hi )/2;
        int mid = result(k , arr);
        int right = result(k+1 , arr);
        int left = inf;
        if(k>1){
            int left = result(k-1 , arr);
        }
        ll resMid = mid*b - (k-1)*x;
        ll resRight = right*b - (k-1)*x;
        ll resLeft = left*b - (k-1)*x;
        if(resRight > resMid && resLeft < resMid){
            res = resRight;
            lo = k ; 
        }
        else if(resLeft >= resMid && resRight < resMid)
        {
            res = resLeft;
            hi = k ; 
        }
        else{
            res = resMid; 
            break;
        } 
    }
    return res ;
}


int main()
{
    int test; 
    cin >> test; 
    while(test--)
    {
        int n , b , x; 
        cin >> n >> b >> x ; 
        vector<int> arr;
        for(int i = 0 ; i< n ; i++)
        {
            int x ; cin >> x ; 
            arr.push_back(x);
        }
        int result = ternary(n , b , x , arr);
        cout<< result <<endl;
        // cout<<result(4,n,b,x,arr);

    }
}