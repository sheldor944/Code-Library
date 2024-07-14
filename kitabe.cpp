#include<bits/stdc++.h>

using namespace std;

#define TC(t)           int t;cin >> t;while(t--)
#define Y               cout << "YES\n"
#define N               cout << "NO\n"
#define ff         first
#define ss         second
#define pb         push_back
#define mp         make_pair
#define ll         long long
#define inf        INT_MAX/3
#define mod        1000000009ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

#define Fastio          ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define read            freopen("out.txt","w",stdout)

long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

bool isLeapYear(int year) {
    if(year % 400 == 0) return true;
    if(year % 100 == 0) return false;
    return year % 4 == 0;
}

int getDaysInMonth(int month, int year) {
    vector<int> daysInMonth = {31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return daysInMonth[month - 1];
}

string getMonthName(int month) {
    vector<string> monthNames = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    return monthNames[month - 1];
}

// Function to calculate the day of the week for the 1st of the month
int calculateStartDay(int currentDay, int startDay, int daysInMonth) {
    int dayOfWeek = startDay;
    // Roll back to the first of the month
    for (int i = currentDay; i > 1; i--) {
        if(dayOfWeek == 0) dayOfWeek = 6;
        else dayOfWeek--;
    }
    // If the month starts on Sunday and the current day is not the first of the month
    if (dayOfWeek == 0 && currentDay != 1) {
        dayOfWeek = 7;
    }
    return dayOfWeek;
}

void printCalendar(int day, int month, int year, string dayName) {
    map<string, int> dayNames = {{"Sun", 0}, {"Mon", 1}, {"Tue", 2}, {"Wed", 3}, {"Thu", 4}, {"Fri", 5}, {"Sat", 6}};
    int daysInMonth = getDaysInMonth(month, year);
    int startDay = calculateStartDay(day, dayNames[dayName], daysInMonth);

    // cout << "Calendar for Month of " << getMonthName(month) << ", " << year << endl;
    cout << "|---------------------------|" << endl;
    cout << "|Sun|Mon|Tue|Wed|Thu|Fri|Sat|" << endl;
    cout << "|---------------------------|" << endl;

    // cout << "srfgsd " << startDay << endl;
    startDay%=7; 

    int currentDay = 1;
    int daysPrinted = 0;
    int extra = daysInMonth-28-(7-startDay);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 7; ++j) {
            if(i==0 && extra>0)
            {
                
                int now = daysInMonth-extra+1;
                for (int xx = now;xx<=daysInMonth;xx++)
                {
                    cout << "|" << setw(3) << xx ;
                    j++;
                }
                
                extra = -1;
                // cout << extra << endl;
            }
            if ((i == 0 && j < startDay) || currentDay > daysInMonth) {
                cout << "| - ";
            } else {
                cout << "|" << setw(3) << currentDay;
                currentDay++;
            }
            daysPrinted++;
        }
        cout << "|" << endl;
        cout << "|---------------------------|" << endl;
        if (currentDay > daysInMonth) {
            if (daysPrinted % 7 != 0) {
                int extraDays = 7 - (daysPrinted % 7);
                for (int k = 1; k <= extraDays; ++k) {
                    cout << "| - ";
                }
                cout << "|" << endl;
                cout << "|---------------------------|" << endl;
            }
            break;
        }
    }
    cout << endl;
}


void solve()
{
    int day, month, year;
    char slash;
    string dayName;
    cin >> day >> slash >> month >> slash >> year >> dayName;

    printCalendar(day, month, year, dayName);
}


int main(){
    Fastio
    TC(t)
    {
        solve();
    }
    return 0;
}