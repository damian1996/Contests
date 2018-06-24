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
#define N 51000


int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t;
  vector<int> vec[N];
  for(int i=0; i<N; i++) {
    vec[i].resize(101);
  }
  cin >> n;
  LL wynik = 0;
  for(int i=n; i>=0; i--) {
      int s = 0, e = i;
      while(e<=n) {
          for(int j=0; j<N; j++) {
              if(vec[j][s]==0 && vec[j][e-1]==0) {
                  if(j>wynik) wynik = j;
                  for(int k=s; k<e; k++) {
                    vec[j][k] = 1;
                  }
                  break;
              }
          }
          s++;
          e++;
      }
  }
  cout << wynik << endl;
  return 0;
}
