// #include "dbg.h"
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve () {
  int n;  cin >> n;
  vector<int> a(n);
  for (auto &ai: a) {
    cin >> ai;
  }
  vector<int> p(n), cnt(n, 1);
  int mex = n;
  for (int i = n - 1; i >= 0; --i) {
    p[i] = mex - a[i];
    cnt[p[i]]--;
    mex = min(mex, p[i]);
  }

  for (auto pi: p) {
    cout << pi << " ";
  }
  cout << "\n";
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; ++t) {
    solve();
  }
}