#include<bits/stdc++.h>
using namespace std;

#define int long long


#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x << " is " << x << endl
#else
#define dbg(x)
#endif

const int N = 2e5; 

bool compareSecond(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    return get<1>(a) < get<1>(b); // Compare second element of each tuple
}

vector<tuple<int , int , int >  > v  ,  cop ; 
int pref[N];
int n ;

int binarySearch(int inner , int outer , int index)
{
    int st = index , ed = n-1 ; 
    int res = -1 ; 
    while(st <= ed)
    {
        int mid = (st+ed)/2;
        dbg(st);
        dbg(ed);
        dbg(mid);
        int currInner = get<0>(v[mid]);
        int currOuter = get<1>(v[mid]);
        dbg(currInner);
        dbg(currOuter);
        if(inner >= currOuter){

            ed= mid -1;
        }
        else{
            inner = currInner;
            res = mid ;
            st = mid + 1;
        }
    }
    return res ; 
}

int32_t main()
{
    cin >> n ; 
    for(int i = 0 ; i< n ; i++)
    {
        int a , b , c ; cin >> a >> b >> c ; 
        v.push_back(make_tuple(a,b,c));
        cop.push_back(make_tuple(a,b,c));
    }
    sort(v.rbegin(), v.rend(), compareSecond);
    for(int i = 0 ; i< n ; i++ )
    {
        pref[i] = get<2>(v[i]);
    }
    for(int i = 1 ; i < n ; i++){
        pref[i] += pref[i-1];
    }
    // cout<<binarySearch(5,7,0)<<endl;
    for(auto u : v){
        cout<< get<0>(u) <<" "<< get<1>(u) <<" "<< get<2>(u)<<endl; 
    }
    int ans = -1 ; 
    // cout<<binarySearch(1 , 3 , 2)<<endl;;

    for(int i = 0 ; i < n ; i++)
    {
        int inner = get<0>(v[i]);
        int outer = get<1>(v[i]);
        int index = binarySearch(inner , outer , i); 
        cout<<" inner "<<inner <<" outer "<<outer<<" index "<<index<<endl;  
        if(index== -1 ){
            continue;
        }
        int sum = pref[index] - pref[i] + get<2>(v[i]);
        cout<< sum <<endl;
        cout<<endl;
        dbg("new index");
        ans = max(ans , sum );

    }
    cout<<ans<<endl;


}