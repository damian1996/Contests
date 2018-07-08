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
const MAXI = 1e5 + 5;
vector<int> G[MAXI];
vll ver;
LL sumi = 0;
bool visited[n];
bool uWas = false;
bool vWas = false;
LL smallest = 0;

void sumSubtree(LL v) {
    sumi += ver[v];
    visited[v] = true;
    for(int i=0; i<G[v].size(); i++) {
        if(!visited[G[v][i]]) {
            sumSubtree(G[v][i]);
        }
    }
}
bool findSmallest(LL r, LL u, LL v) {
    if(r == u) uWas = true;
    else if(r == v) vWas = true;
    if(uWas && vWas) smallest = r;
    if(uWas || vWas) {
      return true;
    }
}

void applicationX(LL small, LL x) {
    ver[small] -= x;
    visited[small] = true;
    for(int i=0; i<G[small].size(); i++) {
      if(!visited[G[v][i]]) {
        applicationX(G[v][i]);
      }
    }
}

int main() {
  std::ios::sync_with_stdio(false);
  LL n, m, t, q, type, u, v, x;
  cin >> n >> q;
  ver.resize(n);
  for(int i=1; i<=n; i++) {
      cin >> ver[i];
  }
  for(int i=0; i<n; i++) {
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
  }
  LL root = 1;
  for(int i=0; i<q; i++) {
    cin >> type;
    switch(type) {
      case 1:
        cin >> v;
        root = v;
        break;
      case 2:
        cin >> u >> v >> x;
        findSmallest(root, u, v);
        applicationX(smallest, x);
        for(int i=1; i<=n; i++) visited[i] = false;
        uWas = false;
        vWas = false;
        break;
      case 3:
        cin >> v;
        sumSubtree(v);
        cout << sumi << endl;
        sumi = 0;
        for(int i=1; i<=n; i++) visited[i] = false;
        break;
      default:
        break;
    }

  }
  return 0;
}
