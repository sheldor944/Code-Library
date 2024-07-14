#include<bits/stdc++.h>
using namespace std;

#define ll long long 

char vowel[5] = {'a' , 'e' , 'i' , 'o' , 'u'};

bool isVowel(char a )
{
    for(int i = 0 ; i< 5 ; i++)
    {
        if(a==vowel[i]){
            return true ;
        }
    }
    return false ;
}

int main()
{
   string s ;
   int k ; 
   cin >> s >> k ;
   int ans = k-1 ; 
   int left = 1 , right = 0 ; 
   char l , r ; 
   l = s[0];
   int v = 0 , c = 0 ;
   s = "#"+s;
   
   for(int i = 1 ; i < s.size() ; i++ )
   {
        if(isVowel(s[i] ) && isVowel(s[i-1]) ) 
        {
            if(v==0){
                v=1;
            }
            v++;
            // cout<< i << " is a v  "<<v<<endl; 
            c=0; 
        }
        else if (  !isVowel(s[i] ) && !isVowel(s[i-1])){
            if(c==0){
                c=1;
            }
            c++;
            v=0;
            // cout<< i << " is a c  "<<c<<endl; 
        }
        // if(i- left +1 >= k )
        // {
            if(( (v >=k || c>=k )))
            {
                // cout<<"here "<< v << " "<< c <<" "<<i<<" "<<left<<endl;

                left = i-(v+c-1) + 1;
                if(c){
                    c--;
                }else{
                    v--;
                }
                //  cout<<"after "<< v << " "<< c <<" "<<i<<" "<<left<<endl;
            }
            else{
                // cout<< ans << " " << i << " " << left << " "<< c <<" "<< v <<endl;
                ans = max (ans , i-left+1);

            }
        // }

   } 
   cout<<ans<<endl;
}