#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define BCK(i, n) for(int i = n-1; i >= 0; i--)
#define FWD(i, a, b) for(int i = a; i < b; i++)
#define pb push_back
#define st first
#define nd second
#define vi vector<int>
#define vll vector<long long>
#define pi pair<int, int>
#define pll pair<long long, long long>
#define vpi vector<pi>
#define vpll vector<pll>
#define mp(a, b) make_pair(a,b)
using namespace std;
typedef long long LL;
typedef double ld;
const LL p = 1000000007;


int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t, ptr = 0;
  string s, sur;
  cin >> s;
  cin >> sur;
  string ss;
  ptr++;
  ss = s[0];
  while(true) {
      if(ptr>=s.size() || s[ptr] >= sur[0] ) {
        ss = ss + sur[0];
        break;
      }
      if(s[ptr] < sur[0]) {
        ss = ss + s[ptr];
        ptr++;
      }
  }

  cout << ss << endl;
  return 0;
}
