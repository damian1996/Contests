#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp(a, b) make_pair(a,b)
#define FWD(i, a, b) for(int i = a; i < b; i++)
using namespace std;
typedef long long LL;

bool isDivisor(int n, int i) {
  if(n%i==0) return true;
  return false;
}

int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t;
  string str, si;
  cin >> n;
  cin >> si;
  std::stringstream ss;
  ss << "a" << si;
  str = ss.str();
  for(int i=1; i<=n; i++) {
      if(isDivisor(n, i)) {
          int s = 1, e = i;
          if((e-s+1)%2==0) {
            for(int i=s, j=e;; i++, j--) {
              if(i>j) break;
              swap(str[i], str[j]);
            }
          }
          else {
            for(int i=s, j=e;; i++, j--) {
              if(i==j) break;
              swap(str[i], str[j]);
            }
          }
      }
  }

  cout << str.substr(1, n) << endl;
  return 0;
}
