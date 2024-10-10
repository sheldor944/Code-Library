#include<bits/stdc++.h>
using namespace std; 

const int N = 1e3 +1 ; 

string s[N]; 
int n, m ; 


int  dp[N][N][6][2];

map<char, int> mp ; 
int f(int str,int pos,   int last,int take ){
    if(str == n  ){
        return (last == 0 ) ? 0 : -last ; 
    }
   
    if(dp[str][pos][last][take] != INT_MIN){
        return dp[str][pos][last][take]; 
    }
    // cout<<s[str][pos]<<endl; 
    // cout<<str<<" "<<pos<<" "<<last<<" "<<take<<endl; 
    if(take ){ // take from this string 
        // cout<<"take condition\n"; 
        if(mp[ s[str][pos] ] == last+1 ){ // current character is perfect to take and add to the result 
            // cout<<" pos take\n";
            if(pos +1 == m ){ // this is the last of this string so taking two ways, either pick the next string or not but we move forward anyways, also adjust the last 
                // cout<<"     last character\n"; 
                dp[str][pos][last][take] = ((last+1 == 5) ? 5 : 0) + max( f(str+1, 0 , (last == 4) ? 0 : last+1 , 1), 
                                                                          f(str+1, 0 , (last == 4) ? 0 : last+1 , 0 )); 
            }
            else{ // not the last of this string so go further for this string 
                // cout<<"     normal add to the string\n"; 
                dp[str][pos][last][take] = ((last+1 == 5) ? 5 : 0) + f(str, pos+1, (last == 4) ? 0 : last+1, 1); 
            }
        }
        else if(s[str][pos] == 'n' or s[str][pos] == 'a' or s[str][pos] == 'r' or s[str][pos] == 'e' or s[str][pos] == 'k'){
            // cout<<"herere\n";
            // cout<<" neg take\n";
            if(pos+1 == m ){ // if last then take 2 ways either take the next one or not and also start from 0 of the next string 
                // cout<<"     neg last char\n";
                dp[str][pos][last][take] = -1 + max( f(str+1, 0, last, 1),
                                                     f(str+1, 0, last, 0));  
            } 
            else{ // not the last character so last stays as it is and move forward ; 
                // cout<<"     normal negative\n";
                dp[str][pos][last][take] = -1 + f(str, pos+1, last, 1); 
            }
        }
        else{
            // cout<<" useless take\n";
            if(pos+1 == m){
                dp[str][pos][last][take] = max( f(str+1, 0, last, 1), f(str+1, 0, last, 0));
            }
            else{
                dp[str][pos][last][take] = f(str, pos+1, last, 1); 
            }
        }
    }
    else{
        // cout<<"skip condition\n";
        dp[str][pos][last][take] = max(f(str+1,pos, last, 0), f(str+1, pos, last, 1)); 
    }
    return dp[str][pos][last][take]; 

}

int main()
{
    mp['n'] = 1 ; 
    mp['a'] = 2 ; 
    mp['r'] = 3 ; 
    mp['e'] = 4 ; 
    mp['k'] = 5 ; 
    
    int test ; 
    cin >> test; 
    while(test--){
        cin >> n >> m ; 
        
        for(int i = 0 ; i <=n ; i++){
            for(int j = 0 ; j <=m ; j++){
                for(int k = 0 ; k < 6 ; k++){
                    for(int l = 0 ; l < 2 ; l++){
                        dp[i][j][k][l] = INT_MIN; 
                    }
                }
            }
        }
        for(int i = 0 ; i <n ; i++){
            cin >> s[i]; 
        }
        // cout<<"hello"<<endl; 
        int x = max(f(0,0,0,0), f(0,0,0,1));
        cout<<x<<endl; 

        // cout<<max(x,y)<<endl; 
        // cout<<"hello"<<endl; 

    }
}