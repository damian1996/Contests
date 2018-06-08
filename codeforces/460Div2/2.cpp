#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define FWD(i, a, b) for(int i = a; i < b; i++)
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp(a, b) make_pair(a,b)
using namespace std;
typedef long long ll;

int sumDigits(ll nr) {
  ll sum = 0;
  while(nr) {
    sum += (nr%10);
    nr /= 10;
  }
  return sum;
}

int main() {
  std::ios::sync_with_stdio(false);
  ll k, i = 0, cnt = 0;
  cin >> k;
  for(int i=19; ; i++) {
    if(sumDigits(i)==10) cnt++;
    if(cnt==k) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
