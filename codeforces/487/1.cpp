#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp(a, b) make_pair(a,b)
#define FWD(i, a, b) for(int i = a; i < b; i++)
using namespace std;
typedef long long LL;

int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t;
  string s;
  cin >> s;
  n = s.size();
  vector<array<int, 3>> kwiatki;
  kwiatki.resize(n);
  for(int i=0; i<n; i++) {
    if(s[i]=='A') {
      kwiatki[i][0] = 1;
      if(i>0) {
        kwiatki[i-1][0] = 1;
      }
      if(i<n-1) {
        kwiatki[i+1][0] = 1;
      }
    }
    if(s[i]=='B') {
      kwiatki[i][1] = 1;
      if(i>0) {
        kwiatki[i-1][1] = 1;
      }
      if(i<n-1) {
        kwiatki[i+1][1] = 1;
      }
    }
    if(s[i]=='C') {
      kwiatki[i][2] = 1;
      if(i>0) {
        kwiatki[i-1][2] = 1;
      }
      if(i<n-1) {
        kwiatki[i+1][2] = 1;
      }
    }
  }
  bool res = false;
  for(int i=0; i<n; i++) {
    if(kwiatki[i][0]==1 && kwiatki[i][1]==1 && kwiatki[i][2]==1) {
      cout << "YES" << endl;
      res = true;
      break;
    }
  }
  if(!res)
    cout << "NO" << endl;
  return 0;
}
