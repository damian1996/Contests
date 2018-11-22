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
  int n, m, t, k;
  string s;
  cin >> n;
  cin >> s;
  int minId = 0;
  for(int i=1; i<n; i++) {
      for(int j=minId+1, k=minId; k<i; j++, k++) {
          if(s[j] > s[k]) {
            minId = i;
            break;
          } else if(s[j] < s[k]) {
            break;
          }
      }
  }
  string minStr = s;
  minStr.erase(minStr.begin() + minId);
  cout << min(minStr, s) << endl;
  return 0;
}
