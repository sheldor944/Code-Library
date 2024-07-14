#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ; 
    cin>> n; 
    vector<int> v ;
    for(int i = 0 ; i< n ; i++     )
    {
        int x ; 
        cin>> x ; 
        v.push_back(x);
    }
    int segCnt = 0 ; 
    int lastZero = -1 ;
    for(int i = 0 ; i< n ; i++)
    {
        int gotTwo = 0 ; 
        if(v[i]==0 && v[i+1]==0 && i+1!= n)
        {
            segCnt++;
            // cout<<i<< " 1st \n";
        }
        else if(v[i]== 0 && (v[i+1]==1 or v[i+1]==2) && (i+1 != n))
        {
            int idx = i+1 ; 
            // cout<<i<<" 2nd start \n";
            while(v[idx]!=0 and idx<n)
            {
                if(v[idx]==2){
                    gotTwo = 1 ; 
                }
                idx++;
            }
            if(gotTwo && idx<n)
            {
                i = idx ;
            }
            else{
                i = idx-1 ; 
            }
            segCnt++;
            // cout<<i<<" 2nd finish  "<<endl;
            // continue;

        }
        else{
             int idx = i ; 
            //  cout<<i<< " 3rd start \n";
            while(v[idx]!=0 and idx<n)
            {
                if(v[idx]==2 && i!=idx){
                    gotTwo = 1 ; 
                }
                idx++;
            }
            if(gotTwo && idx<n)
            {
                i = idx ;
            }
            else{
                i = idx ; 
            }
            segCnt++;
            // cout<<i<<" 3rd \n";
        }
        
        
    }
    cout<<segCnt<<endl;

}
