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
vi G[200005];
int ith[200005];
int element[200005];
int subtree[200005];

/*int dfs(int s, int k, int& cnt) {
    cnt++;
    if(cnt==k) return s;
    int res = -1;
    for(auto& nei : G[s]) {
        res = dfs(nei, k, cnt);
        if(res>0) {
          return res;
        }
    }
    return -1;
}*/

int dfs(int s, int& cnt) {
    cnt++;
    int nodes = 1;
    ith[cnt] = s;
    element[s] = cnt;
    for(auto& nei : G[s]) {
        int recurNodes = dfs(nei, cnt);
        nodes += recurNodes;
    }
    subtree[s] = nodes;
    return nodes;
}

int main() {
  std::ios::sync_with_stdio(false);
  int n, m, q, k, u, cnt = 0;
  cin >> n >> q;
  for(int i=2; i<=n; i++) {
      cin >> k;
      G[k].pb(i);
  }
  dfs(1, cnt);
  for(int i=0; i<q; i++) {
      cin >> u >> k;
      if(k>subtree[u]) {
          cout << -1 << endl;
      } else {
        int diffFromFirst = element[u] - 1;
        cout << ith[k+diffFromFirst] << endl;
      }
  }
  return 0;
}
