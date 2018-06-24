#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp(a, b) make_pair(a,b)
#define FWD(i, a, b) for(int i = a; i < b; i++)
using namespace std;
typedef long long LL;
#define N 5000
#define M 5000
bool visited[N+1];
bool visited2[N+1];
vi G[N+1];
vector<pair<int, int>> toAppend;
vi G2[N+1];

void DFS(int s) {
    visited[s] = true;
    for(auto& x : G[s]) {
        if(!visited[x]) {
            DFS(x);
        }
    }
}

int dfsComputeUtil(int s) {
  visited2[s] = true;
  int wynik = 0;
  for(auto& x : G[s]) {
      if(!visited2[x]) {
          if(!visited[x]) {
            G2[s].pb(x);
            toAppend[s]++;
          }
          int res = dfsComputeUtil(x);
          wynik += res;
      }
  }
  return wynik;
}

int computeFalseDFS(int s, int n) {
    for(int i=0; i<=n; i++)
      visited2[i] = false;

    return dfsComputeUtil(s);
}


int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t, s, a, b;
  cin >> n >> m >> s;
  toAppend.resize(n+1);
  fill(toAppend.begin(), toAppend.end(), 0);
  for(int i=1; i<=n; i++) visited[i] = false;
  for(int i=0; i<m; i++) {
    cin >> a >> b;
    G[a].pb(b);
  }
  DFS(s);

  for(int i=1; i<=n; i++) {
      if(!visited[i]) {
          toAppend[i-1] = computeFalseDFS(i, n);
      }
  }
  std::sort(toAppend.begin(), toAppend.end(), std::greater<int>());
  int res = 0;
  for(int i=0; i<n; i++) {
      if(!visited[i+1]) {
          res++;
          for(auto& neigh : G2[i+1]) {
              if(!visited[neigh]) {
                  visited[neigh] = true;
              }
          }
      }
  }
  cout << res << endl;
  // policz dfsem
  return 0;
}
