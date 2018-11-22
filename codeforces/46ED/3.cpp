#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define RFO(i, n) for(int i = 1; i <= n; i++)
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
  LL n, m, t, end, start;
  cin >> n;
  vector<pair<LL, LL>> input;
  map<LL, int> endpoints;
  vll cnt(n+1);
  REP(i, n) {
      cin >> start >> end;
      input.pb(mp(start, end));
      endpoints[start]++;
      endpoints[end + 1]--;
  }
  fill(cnt.begin(), cnt.end(), 0);
  /* set<int> s( endpoints.begin(), endpoints.end() );
  endpoints.assign( s.begin(), s.end() ); */
  LL open = 0;
  LL last = -1;
  for(auto& it : endpoints) {
      if(last != -1) {
        cnt[open] += it.first - last;
      }
      open += it.second;
      last = it.first;
  }

  RFO(i, n) {
    cout << cnt[i] << " ";
  }
  cout << endl;
  return 0;
}
