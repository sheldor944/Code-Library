#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;


std::string generateRandomLowercaseString(int length) {
    std::string result;
    static const char charset[] = "abcdefghijklmnopqrstuvwxyz";
    static const int charsetLength = sizeof(charset) - 1; // Exclude null terminator
    
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    for (int i = 0; i < length; ++i) {
        result += charset[std::rand() % charsetLength];
    }
    
    return result;
}


signed main()
{
	cout << 1 << "\n";
	srand(time(0));
	int n = rand()%10 + 1;
	cout << n << "\n";
    // int x = rand()%16 +1 ; 
    // cout<<x<<"\n";
	for(int i=1;i<=n;i++)
	{
		int xx;
		xx = rand()%3 + 1;
		cout<<xx<<" ";
		// // std::string str = std::to_string(xx);
		// string str = generateRandomLowercaseString(1);
		// int xxx;
		// xxx = rand()%3 + 1;
		// string str1 = generateRandomLowercaseString(1);
		// // std::string str1 = std::to_string(xxx);
		// cout << str << " " << str1<<endl;
	}
	cout << "\n";
	// for(int i=1;i<=n;i++)
	// {
	// 	int x;
	// 	x = rand()%20 + 1;
	// 	cout << x << " ";
	// }
}