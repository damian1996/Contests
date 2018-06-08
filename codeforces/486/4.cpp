#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define pi pair<int, int>
#define mp(a, b) make_pair(a,b)
#define FWD(i, a, b) for(int i = a; i < b; i++)
using namespace std;
typedef long long LL;

int main() {
  std::ios::sync_with_stdio(false);  
  LL arr[50];
  LL start = 1;
  for(int i=0; i<=31; i++) {
    arr[i] = start;
    start *= 2;
  }

  LL n, m, t;
  cin >> n;
  vector<LL> axis;
  for(int i=0; i<n; i++) {
    cin >> m;
    axis.pb(m);
  }
  
  sort(axis.begin(), axis.end());
  unordered_set<LL> elements;
  for(int i=0; i<n; i++) {
    elements.insert(axis[i]);
  }
  vll result = {axis[0]};

  for(int i=0; i<n; i++) {
      for(int u=0; u<=31; u++) {
        vll newRes;
        newRes.pb(axis[i]);
        LL el1 = axis[i] + arr[u];
        int first = elements.count(el1);
        if(first>0) newRes.pb(el1);
        LL el2 = axis[i] - arr[u];
        int sec = elements.count(el2);
        if(sec>0) newRes.pb(el2);
        if(newRes.size() >= result.size()) {
          result = newRes;
        }
      }
  }
  cout << result.size() << endl;
  for(int i=0; i<result.size(); i++) {
    cout << result[i] << " ";
  }
  cout << endl;

  return 0;
}
