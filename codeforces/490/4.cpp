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
  LL n, m, t;
  cin >> n >> m;
  vector<LL> vec;
  vector<LL> rem;
  vector<pair<LL, LL>> operations;
  vector<LL> pebbles;

  vec.resize(n);
  rem.resize(m);
  vector<LL> rep[m];
  fill(rem.begin(), rem.end(), 0);

  LL k = n/m;
  LL offset = 0;

  for(int i=0; i<n; i++) {
      cin >> vec[i];
      LL d = vec[i]%m;
      rem[d]++;
      rep[d].pb(i);
  }

  for(int i=0; i<m; i++) {
      if(rem[i]>k) {
          LL diff = rem[i] - k;
          for(int j=0; j<diff; j++) {
              pebbles.pb(i);
          }
      }
      else if(rem[i]<k) {
          LL diff = k - rem[i], siz = pebbles.size(), toPop;
          toPop = (diff > siz) ? siz : diff;
          rem[i] = (diff>siz) ? (rem[i] + siz) : k;

          for(int j=0; j<toPop; j++) {
              LL from = pebbles[siz-j-1];
              pebbles.pop_back();
              operations.pb(mp(from, i));
          }
      }
      offset += pebbles.size();
  }

  for(int i=0; i<m; i++) {
      if(rem[i]<k) {
          LL diff = k - rem[i], siz = pebbles.size(), toPop;
          toPop = (diff > siz) ? siz : diff;
          rem[i] = (diff>siz) ? (rem[i] + siz) : k;

          for(int j=0; j<toPop; j++) {
              LL from = pebbles[siz-j-1];
              pebbles.pop_back();
              operations.pb(mp(from, i));
          }
      }
      offset += pebbles.size();
  }
  LL siz = operations.size();
  for(int i=0; i<siz; i++) {
      LL from = operations[i].first;
      LL to = operations[i].second;
      LL add = ((from < to) ? (to - from) : (to + m - from));
      LL toAdd = rep[from][rep[from].size() - 1];
      vec[toAdd] += add;
      rep[from].pop_back();
  }

  cout << offset << endl;
  for(int i=0; i<n; i++) {
    cout << vec[i] << " ";
  }
  cout << endl;

  return 0;
}
