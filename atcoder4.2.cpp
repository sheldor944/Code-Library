#include<bits/stdc++.h>
using namespace std;

int main()
{
    double test ; 
    cin >> test; 
    while(test--)
    {
        double n ; 
        cin >> n ;
        double a , b ; 
        cin >> a >> b ;
        double maxP = ceil(n/2)*n;
        double blankRow = n - ceil(n/2);
        // cout<<blankRow<<endl;
        // cout<< maxP<<endl;

        if(a > n){
            cout << "No\n";
            continue;
        }
        else{
            if(a <= blankRow){
                maxP -= (n-blankRow)*a;  
                // cout<<"a <= blankcRow\n";
            }
            else{
                maxP -= (n-blankRow)*blankRow;
                // cout<< n <<" "<<blankRow<<endl;
                // cout<< " reduction is "<< (n-blankRow)*blankRow<<endl;
                // cout<<" afterr reduction "<<maxP<<endl;
                double inRaw = n - blankRow;
                // cout<< "is Raw " <<inRaw<<endl; 
                double pawn = (inRaw*2)-1;
                // cout<< "total pawn is "<<pawn<<endl;
                double rem = a- blankRow;
                // cout<<"remaing a is "<<rem<<endl;
                double total = (rem/2) * (2*pawn- (rem-1)*2);
                // cout<< "total is "<<total<<endl;
                maxP-=total;  
                // cout<<"maximum pawn is "<<maxP<<endl;

            }
        }
        // cout<< n <<endl;
        if(maxP >= b){
            cout<<"Yes\n";
        }
        else{
        cout<<"No\n";
        }
    }
}