#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 9;

void hashing(string s, vector<int> &hashValue)
{
    int size = s.size();
    const int p = 31;
    const int m = 1e9 + 9;
    long long p_pow = 1;
    s = "#" + s;
    for (int i = 1; i <= size; i++)
    {
        hashValue[i] = (hashValue[i - 1] + (s[i] - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
}

long long power(int x, unsigned int y, unsigned int M)
{
    if (y == 0)
        return 1;

    long long p = power(x, y / 2, M) % M;
    p = (p * p) % M;

    return (y % 2 == 0) ? p : (x * p) % M;
}


long long modInverse(int A, int M)
{

    return power(A, M - 2, M);
}


long long calculateHash(vector<int> hashValue, int s, int e)
{
    long long hash = hashValue[e] - hashValue[s-1];
    // cout<<hash<<endl;
    hash = (hash* modInverse( power(31 , s-1 , mod), mod ) % mod);

    return hash; 
}

int palindrome(int s, int e, int len , vector<int> &hashValue , vector<int> &hashValueBackward)
{
    int lo = s;
    int high = e;
    int mid , ans =-1 ; 
    while (lo < high)
    {
        mid = (lo + high) / 2;
        int forwarHash = calculateHash(hashValue , s, mid);
        int backwardHash = calculateHash(hashValueBackward , high , mid);
        cout<<"hash value\n";
        cout<<forwarHash<<" "<<backwardHash<<endl;

        if(forwarHash == backwardHash)
        {
            lo = mid +1;
            ans = mid ; 
        }   
        else{
            high = mid ;
        }
    }
   
        return ans ; 
    
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string s, rev;
        cin >> s;
        rev = s;
        vector<int> hashValue(s.size() + 1, 0), hashValueBackward(s.size() + 1, 0);
        hashing(s, hashValue);
        reverse(rev.begin(), rev.end());

        hashing(rev, hashValueBackward);
        // for(auto i : hashValueBackward)
        // {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // cout<<calculateHash(hashValueBackward , 2 , 3 )<<endl;
        // cout<<power(31 , (2-1) , mod)<<endl;

        string pref = "", suff = "";
        int start = 0, end = s.size() - 1;
        while (start < end && s[start] == s[end])
        {
            pref += s[start];
            suff = s[end] + suff;
            start++;
            end--;
        }
        cout<<start <<" "<<end<<endl;
        if (start >= end)
        {
            cout << pref << suff << endl;
        }
        else
        {
            string palindrom;
            int prefixPalindromeMid = palindrome(start , end ,0 , hashValue , hashValueBackward );
            int suffixPalindromeMid = palindrome(start , end , 0 , hashValueBackward , hashValue);
            cout<<prefixPalindromeMid<<" "<<suffixPalindromeMid<<endl;
            if(prefixPalindromeMid > suffixPalindromeMid)
            {
                cout<<pref;
                for(int i = start ; i < start + prefixPalindromeMid ; i++)
                {
                    cout<<s[i];
                }
                cout<<suff<<endl;
            }
            else{
                cout<<pref;
                for(int i = start ; i < start + suffixPalindromeMid ; i++)
                {
                    cout<<rev[i];
                }
                cout<<suff<<endl;
            }
        }
    }
}