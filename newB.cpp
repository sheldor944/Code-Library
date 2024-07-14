#include<bits/stdc++.h>
using namespace std;
struct CompareGreater {
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
};

set<int, CompareGreater> getDivisors(int n) {
    set<int,CompareGreater> divisors;
    divisors.insert(1);
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) {
            divisors.insert(i);
            divisors.insert(n/i);
        }
    }
    return divisors;
}


int main() {
    vector<set<int,CompareGreater>> divisors;
    for (int num = 1; num <= 1000; num++) {
        divisors.push_back(getDivisors(num));
    }
    int test ; 
    cin>> test ; 
    while(test--)
    {
        int n ; 
        // cin >> n ;
        n = test;  
        vector<int> check(n+1 , 0);
        int cnt = 0, last = 0 ;
        for(int i = n ; i >=1 ; )
        {
            for(int element : divisors[i] )
            {
                if(check[element]!= 2 && element < i)
                {
                    i -=element;
                    check[i]++;
                    cnt ++ ; 
                    last = i;
                    break;
                }
            }
        }
        if(last != 1 )
        {
            cout<<" for n "<<test <<endl;
        }
        if(cnt >1000  )
        {
            cout<<n<<endl;
        }
    }

    return 0;
}
