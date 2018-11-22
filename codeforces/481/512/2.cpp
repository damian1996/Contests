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


int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t, d;
  float x, y;
  cin >> n >> d;
  cin >> t;
  for(int i=0; i<t; i++)
  {
      //d,0 i 0,d i n-d,n i n,n-d
      cin >> x >> y;
      bool res = true;
      if(!((x+y)>=d && (x+y)<=2*n-d)) {
        res = false;
      }
      if(!((x-y)>=-d && (x-y)<=d)) {
        res = false;
      }
      if(res) cout << "YES" << endl;
      else cout << "NO" << endl;
  }
  return 0;
}
