#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

ll N = 1e18;
signed main()
{
	// cout << 1 << "\n";
	srand(time(0));
	// ll n = rand(%)
	ll n = rand() +1e11+123;
	n %=20;
	cout << n+1 << "\n";
	n++;
	for(int i = 0 ; i < n ; i++){
		ll x = rand() + 1e11; 
		x%=n ;
		cout<<x+1<<" "; 

	}
    // ll x = rand() +1e11 + 12345678912  ; 
    // if(n < x){
	// 	cout<< n << "\n";
	// 	cout<< x << "\n";

	// }
	// else{
	// 	cout<< x << "\n";
	// 	cout<< n << "\n";
		
	// }
	// cout<<x<<"\n";
	// for(int i=1;i<=n;i++)
	// {
	// 	int xx;
	// 	xx = rand()%10 + 1;
	// 	cout << xx << " ";
	// }
	cout << "\n";
	// for(int i=1;i<=n;i++)
	// {
	// 	int x;
	// 	x = rand()%20 + 1;
	// 	cout << x << " ";
	// }
}