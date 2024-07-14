// C++ program to calculate the number of
// pairs with product is perfect square
#include <bits/stdc++.h>
using namespace std;

// Prime[] array to calculate Prime Number
long long prime[300001] = { 0 };

// Array k[] to store the value of k for
// each element in arr[]
long long k[300001] = { 0 };

// For value of k, Sieve function is
// implemented
void Sieve()
{
	// Initialize k[i] to i
	for (long long i = 1; i < 300001; i++)
		k[i] = i;

	// Prime Sieve
	for (long long i = 2; i < 300001; i++) {

		// If i is prime then remove all
		// factors of prime from it
		if (prime[i] == 0)
			for (long long j = i; j < 300001; j += i) {

				// Update that j is not
				// prime
				prime[j] = 1;

				// Remove all square divisors
				// i.e. if k[j] is divisible
				// by i*i then divide it by i*i
				while (k[j] % (i * i) == 0)
					k[j] /= (i * i);
			}
	}
}

// Function that return total count
// of pairs with perfect square product
long long countPairs(long long arr[], long long n)
{
	// Map used to store the frequency of k
	unordered_map<long long, long long> freq;

	// Store the frequency of k
	for (long long i = 0; i < n; i++) {
		freq[k[arr[i]]]++;
	}

	long long sum = 0;

	// The total number of pairs is the
	// summation of (fi * (fi - 1))/2
	// for (auto i : freq) {
	// 	sum += ((i.second - 1) * i.second) / 2;
	// }
    // sum += freq[0] * (n-freq[0]);	
    return sum;
}

// Driver code
int main()
{
    long long n ; cin >> n ; 
	long long arr[n+123];

    for(long long i = 0; i < n ; i++)
    {
        cin >> arr[i];
    }

	// Size of arr[]
	
	// To pre-compute the value of k
	Sieve();

	// Function that return total count
	// of pairs with perfect square product
    long long ans = countPairs(arr, n) ; 
    int p = 0 ;
    for(long long i = 0 ; i<n ; i++)
    {
        if(arr[i]== 0)
        {
            p += (n-1);
        }
    }
    ans += (p/2);
	cout << ans << endl;

	return 0;
}
