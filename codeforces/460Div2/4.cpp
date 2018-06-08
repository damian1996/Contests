#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define FWD(i, a, b) for(int i = a; i < b; i++)
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define pi pair<int, int>
#define mp(a, b) make_pair(a,b)
using namespace std;
typedef long long ll;

int main() {
  std::ios::sync_with_stdio(false);
  ll m, n, x, y;
  string in;
  cin >> n >> m;
  vll graph[n];
  cin >> in;
  for(int i=0; i<m; i++) {
    cin >> x >> y;
    graph[x].pb(y);
  }
  return 0;
}
