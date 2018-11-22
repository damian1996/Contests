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
  int n, m, t, prev;
  cin >> n >> m;
  vi neigh[m];
  vi G(n+1);
  bool visited[n+1];
  bool acceptable[n+1];

  long long res = n;

  for(int i=1; i<=n; i++) {
    G[i] = -1;
    acceptable[i] = true;
    visited[i] = false;
  }
  int frst;
  cin >> frst;
  for(int i=1; i<n; i++) {
    cin >> t;
    G[frst] = t;
    frst = t;
  }
  G[frst] = 0;

  for(int i=1; i<m; i++) {
      cin >> prev;
      for(int j=1; j<n; j++) {
          cin >> t;
          if(G[prev] != t) {
              acceptable[prev] = false;
          }
          prev = t;
      }
      if(G[prev] != 0) {
          acceptable[prev] = false;
      }
  }

  for(int i=1; i<=n; i++) {
      if(!visited[i] && acceptable[i] && G[i] != 0) {
          visited[i] = true;
          int next = G[i];
          if(next == 0) continue;
          long long pathLen = 2;
          res = res + pathLen - 1;
          while(1) {
              if((visited[next] == false) && acceptable[next] && G[next] != 0) {
                visited[next] = true;
                next = G[next];
                if(next == 0) continue;
                pathLen = pathLen + 1;
                res = res + pathLen - 1;
              } else {
                visited[next] = true;
                break;
              }
          }
      }
      else if(!visited[i] && !acceptable[i]) {
          visited[i] = true;
      }
  }

  cout << res << endl;
  return 0;
}
