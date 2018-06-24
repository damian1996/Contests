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
const int N = 5010;
int dp[N][N];
int temp[N];

int main() {
  std::ios::sync_with_stdio(false);
  //dp[i][j] which stores the number of such programs ending with statement i at indent j.
  int n, m, t;
  cin >> n;

  dp[0][0] = 1;
  vector<char> vec;
  vec.resize(n);
  for(int i=0; i<n; i++) {
      cin >> vec[i];
  }
  int indent = 0;
  for(int i=0; i<n; i++) {
      if(vec[i]=='f') {
          dp[i+1][0] = 0;
          for (int j = 1; j < n; ++j) {
              dp[i+1][j] = dp[i][j-1];
          }
      }
      else if(vec[i]=='s') {
          for(int k=0; k<n; k++)
              temp[k] = 0;

          for(int k=n-1; k>=0; k--)
              temp[k] = (temp[k+1] + dp[i][k])%p;

          for(int j=0; j<n; j++)
              dp[i+1][j] = temp[j];
      }
  }
  LL wynik = 0;
  for(int k=0; k<n; k++) {
    wynik = (wynik + dp[n-1][k])%p;
  }
  cout << wynik << endl;
  return 0;
}
