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
  int n, m, t;
  cin >> n;
  LL din;
  vll ein(n+1);
  ein[0] = 0;
  for(int i=1; i<=n; i++) {
    cin >> din;
    ein[i] = din + ein[i-1];
  }
  LL pos = 0;
  din = ein[n]/2;
  for(int i=1; i<=n; i++) {
    if(ein[i]<=din) {
      pos = i;
    }
    else {
      break;
    }
  }
  for(int i=pos; i>=0; i--) {
      bool aa = binary_search(ein.begin(), ein.end(), ein[i]);
      bool bb = binary_search(ein.begin(), ein.end(), ein[n]-ein[i]);
      if(aa && bb) {
        cout << ein[i] << endl;
        break;
      }
  }
  return 0;
}
