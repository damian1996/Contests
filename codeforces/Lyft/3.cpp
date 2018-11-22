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

int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t, cell;
  cin >> n;
  vi cells(n+1);
  vpi p;
  bool results[n+1];
  for(int i=0; i<=n; i++) results[i] = false;
  for(int i=1; i<=n; i++) {
    cin >> cells[i];
    p.pb(mp(cells[i], i));
  }
  sort(p.begin(), p.end(), std::greater<pair<int, int>>());
  std::string s(n+1, 'x');
  s[p[0].nd] = 'B';
  results[p[0].nd] = false;
  for(int i=1; i<n; i++) {
      int tmp = p[i].st;
      results[p[i].nd] = false;
      for(int j=p[i].nd - tmp; j>=1; j -= tmp) {
          if((cells[j] > tmp) && !results[j]) {
                results[p[i].nd] = true;
                break;
          }
      }
      for(int j= p[i].nd + tmp; j<=n; j += tmp) {
            if((cells[j] > tmp) && !results[j]) {
                  results[p[i].nd] = true;
                  break;
            }
      }
      if(results[p[i].nd]) s[p[i].nd] = 'A';
      else s[p[i].nd] = 'B';
  }
  for(int i=1; i<=n; i++)
      cout << s[i];
  cout << endl;
  return 0;
}
