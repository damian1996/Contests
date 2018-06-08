#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define FWD(i, a, b) for(int i = a; i < b; i++)
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp(a, b) make_pair(a,b)
using namespace std;
typedef long long LL;

int main() {
  std::ios::sync_with_stdio(false);
  LL n, m, t, k;
  cin >> n >> k;
  for(int i=0; i<k; i++) {
    if(n%10!=0) {
      n -= 1;
    } else {
      n /= 10;
    }
  }
  cout << n << endl;
  return 0;
}
