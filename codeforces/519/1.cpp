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
  int n, m, t, k, maxi, sumE;
  cin >> n;
  vi a_arr(n+1);
  a_arr[0] = 0;
  for(int i=1; i<=n; i++) {
    cin >> a_arr[i];
  }
  vi res;
  int possibilites = 0;
  for(int i=1; i<=n; i++) {
      vi restore(i);
      bool canBe = true;
      for(int j=1; j<=i; j++) {
        restore[j-1] = a_arr[j] - a_arr[j-1];
      }
      int heh = 0;
      for(int j=i+1; j<=n; j++) {
          int ai = a_arr[j] - a_arr[j-1];
          if(ai != restore[heh]) {
            canBe = false;
            break;
          }
          heh = (heh + 1) % i;
      }
      if(canBe) {
          res.pb(i);
          possibilites++;
      }
  }

  cout << possibilites << endl;
  for(int i=0; i<res.size(); i++)
    cout << res[i] << " ";
  cout << endl;
  return 0;
}
