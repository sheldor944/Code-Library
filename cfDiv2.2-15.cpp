#include<bits/stdc++.h>
using namespace std;
#define ll long long


bool valid(int i , int j )
{
    if(i==0 or j ==0 or i == 6 or j==6){
        return false;
    }
    return true;
}


int  main()
{
    ll  test ; 
    cin >> test ; 
    while(test--)
    {
        char s[7][7];
        for(int i = 0 ; i<7 ; i++)
        {
            for(int j = 0 ; j< 7 ; j++)
            {
                cin >> s[i][j];
            }
            
        }       
        int matrix [7][7];
        int marker [7][7];
        memset (marker , 0 , sizeof(marker));

        memset (matrix , 0 , sizeof(matrix));
        priority_queue<pair<int, int > > pq ;
        priority_queue<pair<int, pair<int, int> > , vector<pair<int, pair<int, int>>> , greater<pair<int, pair<int, int>>>  > number ;
        int center = 0 ; 
        for(int i = 0 ; i<  7 ; i++)
        {
            for(int j = 0 ; j< 7 ; j++ )
            {
                if(valid(i,j) && s[i][j]=='B'){
                    if(s[i-1][j]=='B' && s[i+1][j]=='B' && s[i][j-1]=='B' && s[i][j+1]=='B' )
                    {
                        matrix[i-1][j] ++;
                        matrix[i+1][j] ++;
                        matrix[i][j-1] ++;
                        matrix[i][j+1] ++;
                        marker[i][j] =1 ;
                        center++ ; 
                        pq.push({i,j});
                    }
                }
            }
        }
        for(int i = 0 ; i<7 ; i++){
            for(int j =0 ; j<7 ; j++)
            {
                if(matrix[i][j]){
                    number.push({matrix[i][j], {i,j}});
                }
            }
        }
        while(center){
            auto topper = number.top();
            int cnt = topper.first;
            int x = topper.second.first;
            int y = topper.second.second;

            

        }

      
    }
}
