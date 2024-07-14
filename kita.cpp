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

int binary_search(int lo , int hi , int val, vector<int>& suff )
{
    int res = -1 ; 
    while(lo<=hi){
        int mid = (hi+lo)/2;
        if(suff[mid] > val ){
            lo = mid +1 ;
        }
        else{
            hi = mid-1;
            res = mid;
        }
    }
    return res ; 
}

int32_t main()
{
//    int n ; cin >> n ; 
//    cout<<n<<endl;
    int t ; cin>>t ; 
    while(t--)
    {
        int n , k  ; cin >> n >> k ;
        vector<int> v , suff(n+1,0);
        for(int i = 0 ; i< n ; i++)
        {
            int x; cin >> x ; 
            v.push_back(x);
            suff[i] = x ; 
        } 

        for(int i = n-1 ; i> 0 ; i--)
        {
            suff[i-1] += suff[i];
        }
        // cout<<binary_search(0,n-1, 14, suff)<<endl;
        dbg(binary_search(0,n-1,14 , suff));
        for(auto u : suff){
            dbg(u);
        }
        int st = 0 , ed = n-1;
        // cout<<"here"<<endl;
        // while(k!= 0)
        // {
        for(int i = 0 ; i<=ed ; i++)
        {
            int a = v[i] ; 
            dbg(a);
            dbg(k);
            if(k ==0 or st> ed){
                break;
            }
            // cout<<"array is \n";
            // for(auto u : v){
            //     cout<<u<<" ";
            // }
            // cout<<endl;
            if(2*a <= k)
            {
             
                int right = suff[ed+1];
                k-= 2*a ; 

                int sum = 0 ;
                v[i] = 0 ; 
                st++;
                dbg(st);
                dbg(ed);

                dbg(k);
                int searchVal = a+suff[ed+1];
                dbg(searchVal);
                int extra = suff[ed+1];
                dbg(extra);
                int index = binary_search(st , ed+1 , a + suff[ed+1], suff);
                dbg(index);
                if(index > ed){
                    v[ed] - 
                }
                int rem = a - suff[index] - extra;
                dbg(rem); 
                v[index - 1] -= rem ; 
                ed = index -1;
                // if(rem){
                //     ed = index -1 ; 
                // }
                // else{
                //     ed = index;
                // }
                // for(int i = ed ; i >=st ; i-- )
                // {
                //     if(sum + v[i] <= a)
                //     {
                //         sum += v[i];
                //         // maybe not necessary
                //         ed = i-1;
                //         v[i]=0;
                //         dbg(sum+v[i]);
                //     }
                //     else{
                //         v[i] = v[i] - a + sum;
                //         ed = i ; 
                //         dbg(v[i]);
                //         dbg("before break");
                //         dbg(ed);
                //         break;
                //     }
                // }
                dbg(ed);
                // cout<<"here2";
            }
            else{
                // st = i ; 
                dbg("there");
                int half = k/2 ; 
                int rest = k&1 ; 
                dbg(half);
                dbg(rest);
                dbg(v[st]);
                v[st] -= half ;
                dbg(v[st]); 
                dbg(ed);
                dbg(v[ed]);
                for(int i = ed ; i >= st ; i--)
                {
                    if(half==0)break; 
                    if(half >= v[i]){
                        dbg("here");
                        dbg(i);
                        dbg(v[i]);
                        dbg(half);
                        half -= v[i];
                        v[i] = 0 ; 
                        ed = i-1 ; 
                    }
                    else{
                        v[i] -= half ;
                        half = 0 ; 
                        ed = i ; 
                        dbg(ed);
                        // cout<<"here ed is "<<ed<<endl;
                        break;
                    }
                }
                for(auto u : v){
                    dbg(u);
                }
                int total = rest + half ; 
                dbg(total);
                dbg(st);
                dbg(ed);
                if(v[st] == 1 && rest ==1){
                    st++;
                }
                // for(int i = st ; i <= ed ; i++)
                // {
                //     if(total ==0 )break;
                //     if(total >= v[i])
                //     {
                //         total-= v[i];
                //         v[i] = 0 ; 
                //         st = i+1 ; 
                //         dbg("ekhane");
                //         dbg(st);
                //     }
                //     else{
                //         v[i]-=total ; 
                //         dbg("ekhanew");
                //         st = i ; 
                //     }
                // }
                k = 0 ; 
                break;
                // different case, half the k and split it 
            }
        }
        //     break ; 
        // }
        dbg(st);dbg(ed);
        // cout<< st<<" "<<ed<<endl;
        cout<<n - (ed-st +1)<<endl;
    }

}