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
  int n, m, t;
  int a, b, c, d;
  char kind;
  vector<pair<int, char>> abcd;
  cin >> a >> b >> c >> d;
  abcd.push_back(a, "A");
  abcd.push_back(b, "B");
  abcd.push_back(c, "C");
  abcd.push_back(d, "D");
  sort(abcd.begin(), abcd.end());
  int sum = a + b + c + d;
  for(int n=0; n<=50; n++) {
      for(int m=0; m<=50; m++) {
          for(int i=0; i<sum/2; i++) {
              
          }
      }
  }

  return 0;
}
