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
  unsigned N, result = 0;
  cin >> N;
  unsigned sqr = sqrt(N);
  for(int i = 1; i < N; ++i) {
      if(N%i == 0) {
          int k = N/i - 1;
          int sq2 = sqrt(k);
          for(int z = 2; z < k; ++z) {
              if(k%z == 0 && k/z > 2) {
                ++result;
                //cout << i << ' ' << z*i << ' ' << (k/z-1)*z*i << endl;
              }
          }
      }
  }
  cout << result << endl;
  return 0;
}
