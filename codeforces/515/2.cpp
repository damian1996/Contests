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
  int n, m, t, r;
  cin >> n >> r;
  vi house(n);
  for(int i=0; i<n; i++) {
    cin >> house[i];
  }

  int needed = 0;
  for(int i=0; i<n;) {
      if(house[i] == 1) {
          needed++;
          for(int l = i - r + 1; l < i; l++) {
              house[l] = 1;
          }
          bool set = false;
          int to = i+r-1;
          if(to >= n) to = n-1;
          for(int l = i+1; l <= to; l++) {
              bool canBeUnable = false;
              if(house[l] == 1) {
                  int secto = l+r-1;
                  if(secto >= n) secto = n-1;
                  for(int k=l+1; k<=secto; k++) {
                      if(house[k] == 1) {
                          canBeUnable = true;
                      }
                  }
                  if(!canBeUnable) {
                      i = l;
                      set = true;
                      break;
                  }
              } else {
                house[l] = 1;
              }
          }
          if(set) continue;
          i = i + r;
      } else {
          i++;
      }
  }
  int counter = 0;
  for(int i=0; i<n; i++) {
    if(house[i] == 0) {
      counter++;
      break;
    }
  }

  if(counter) cout << -1 << endl;
  else cout << needed << endl;

  return 0;
}
