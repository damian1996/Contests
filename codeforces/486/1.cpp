#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp(a, b) make_pair(a,b)
#define FWD(i, a, b) for(int i = a; i < b; i++)
using namespace std;
typedef long long LL;

int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t, k;
  vi ratings;
  cin >> n >> k;
  for(int i=0; i<n; i++) {
    cin >> m;
    ratings.pb(m);
  }
  vi team;
  vi indexes;
  bool res = false;
  for(int i=0; i<n; i++) {
    if(find(team.begin(), team.end(), ratings[i]) == team.end()) {
      team.pb(ratings[i]);
      indexes.pb(i+1);
      if(team.size()==k) {
        res = true;
        break;
      }
    }
  }
  if(res) {
    cout << "YES" << endl;
    for(int i=0; i<k; i++) {
      cout << indexes[i] << " ";
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
