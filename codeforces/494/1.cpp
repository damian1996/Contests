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
vector<int> vals;

int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t;
  cin >> n;
  vals.resize(101);
  fill(vals.begin(), vals.end(), 0);
  for(int i=0; i<n; i++) {
    cin >> m;
    vals[m] += 1;
  }
  int maxi = -1;
  for(int i=1; i<=100; i++) {
    if(maxi < vals[i]) maxi = vals[i];
  }
  cout << maxi << endl;
  return 0;
}
