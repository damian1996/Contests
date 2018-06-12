#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp(a, b) make_pair(a,b)
#define FWD(i, a, b) for(int i = a; i < b; i++)
#define INF 1e10
using namespace std;
typedef long long LL;

int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t;
  vector<LL> sizes;
  vector<LL> costs;
  vector<pair<LL, LL> > results;
  cin >> n;
  sizes.resize(n);
  costs.resize(n);
  results.resize(n);

  REP(i, n) cin >> sizes[i];
  REP(i, n) cin >> costs[i];
  fill(results.begin(), results.end(), mp(INF, INF));

  #pragma omp parallel for
  REP(i, n) {
      for(int j=i-1, k=i+1; j>=0 || k<n; j--, k++) {
          if(j>=0 && sizes[j] < sizes[i])
              results[i].first = min(results[i].first, costs[j]);
          if(k<n && sizes[i] < sizes[k])
              results[i].second = min(results[i].second, costs[k]);
      }
  }
  bool res = false;
  LL minSum = 2*INF;
  REP(i, n) {
      if(results[i].first != INF && results[i].second != INF) {
        res = true;
        minSum = min(minSum, costs[i]+results[i].first+results[i].second);
      }
  }
  if(res) cout << minSum << endl;
  else cout << -1 << endl;
  return 0;
}
