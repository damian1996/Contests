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
vector<double> ai;
double pre[5000];
int main() {
  std::ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  ai.resize(n);
  for(int i=0; i<n; i++) {
    cin >> ai[i];
  }
  double res = 0.0;
  for(int i=0; i<n; i++) {
    res += ai[i];
    pre[i] = res;
  }

  double maxi = 0.0;
  for(int i=k; i<=n; i++) {
    for(int j=0; j<=(n-i); j++) {
      int b = j+i-1;
      double mi = (pre[b] - pre[j-1])/(b-j+1.0);
      if(mi > maxi)  maxi = mi;
    }
  }
  cout << fixed << setprecision(10) << maxi << endl;
  return 0;
}
