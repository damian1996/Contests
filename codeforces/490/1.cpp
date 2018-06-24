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
  cin >> n >> k;
  vi skills;
  skills.resize(n);
  for(int i=0; i<n; i++) {
    cin >> skills[i];
  }
  int s = 0, e = n-1, w = 0;
  for(;;) {
    bool was = false;
    if(skills[s]<=k) {
      w++;
      s++;
      was = true;
    }
    else if(skills[e]<=k) {
      e--;
      w++;
      was = true;
    }
    if(!was) break;
    if(s>e) break;
  }
  cout << w << endl;
  return 0;
}
