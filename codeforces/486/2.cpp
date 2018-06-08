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
  cin >> n;
  vector<string> strs; 
  for(int i=0; i<n; i++) {
    cin >> s;
    strs.pb(s);
  } 
  bool res = true;
  for(int i=0; i<n-1; i++) {
      for(int j=i+1; j<n; j++) {
        if (strs[i].find(strs[j]) != std::string::npos) {
           swap(strs[i], strs[j]);
        }
        else {
           if (strs[j].find(strs[i]) == std::string::npos) {
              res = false;
              break;
           }
        }
      }
  }
  if(!res) {
    cout << "NO" << endl;
  }
  else {
    cout << "YES" << endl;
    for(int i=0; i<n; i++) {
      cout << strs[i] << endl;
    }
  }
  return 0;
}
