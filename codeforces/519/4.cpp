#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t, prev;
  cin >> n >> m;
  vi G(n+1), P(n+1);
  bool acceptable[n+1];
  long long res = n;
  for(int i=1; i<=n; i++) {
      G[i] = -1;
      P[i] = -1;
      acceptable[i] = true;
  }

  for(int i=0; i<m; i++) {
      cin >> prev;
      P[prev] = 0;
      for(int j=1; j<n; j++) {
          cin >> t;
          if(G[prev] == -1) {
            G[prev] = t;
            P[t] = prev;
          }
          if(acceptable[prev] && G[prev] != t)
              acceptable[prev] = false;
          prev = t;
      }
      acceptable[prev] = false;
  }

  for(int i=1; i<=n; i++) {
      if(acceptable[i]) {
          int iter = i;
          while(P[iter] && acceptable[P[iter]]) iter = P[iter];
          acceptable[iter] = false;
          long long pathLen = 1;
          int next = G[iter];
          while(acceptable[next]) {
              acceptable[next] = false;
              next = G[next];
              pathLen = pathLen + 1;
          }
          res += pathLen * (pathLen + 1) / 2;
      }
  }

  cout << res << endl;
  return 0;
}
