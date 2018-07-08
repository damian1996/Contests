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
  LL n, m, t, q, b;
  cin >> n >> q;
  vll vec(n);
  vi il(33);
  vll pots(33);
  for(int i=0; i<33; i++) il[i] = 0;
  for(int i=0; i<33; i++) pots[i] = 1<<i;

  for(int i=0; i<n; i++) {
    cin >> vec[i];
    int v = vec[i];
    int d = 0;
    while(v>1) {
      d++;
      v = v/2;
    }
    il[d] += 1;
  }

  for(int i=0; i<q; i++) {
    LL w = 0;
    cin >> b;
    for(int j=32; j>=0; j--) {
        LL pot = pots[j];
        LL ile = il[j];

        if(b>=pot && b>0) {
            LL bc = b;
            LL dziel = bc/pot;
            if(dziel >= ile) {
              b -= (pot*ile);
              w += ile;
              ile = 0;
            }
            else {
                b -= (pot*dziel);
                w += dziel;
                ile -= dziel;
            }
        }
     }
     if(w>0 && b==0) cout << w << endl;
     else cout << -1 << endl;
  }

  return 0;
}
