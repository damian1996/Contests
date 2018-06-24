#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp(a, b) make_pair(a,b)
#define FWD(i, a, b) for(int i = a; i < b; i++)
#define INF 1e9

using namespace std;
typedef long long LL;

int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t;
  string up, down;
  cin >> up;
  cin >> down;
  n = up.size();
  LL dp[n][4];
  for(int i=0; i<n; i++)
      for(int j=0; j<4; j++)
          dp[i][j] = 0;
  // 0 - .. , 1 - .x, 2 - x. , 3 - xx
  dp[0][0] = (up[0]=='0' && down[0]=='0') ? 0 : -INF;
  for(int i=1; i<n; i++) {
      if(up[i]=='0' && down[i]=='0') {
          dp[i][3] = max(dp[i-1][0]+1, max(dp[i-1][1]+1, dp[i-1][2]+1));
          dp[i][1] = dp[i-1][0]+1;
          dp[i][2] = dp[i-1][0]+1;
          dp[i][0] = max(max(dp[i-1][0], dp[i-1][1]), max(dp[i-1][2], dp[i-1][3]));
      }
      else if(up[i]=='X' && down[i]=='0') {
          dp[i][3] = dp[i-1][0]+1;
          dp[i][2] = max(max(dp[i-1][0], dp[i-1][1]), max(dp[i-1][2], dp[i-1][3]));

          dp[i][0] = -INF;
          dp[i][1] = -INF;
      }
      else if(up[i]=='0' && down[i]=='X') {
          dp[i][3] = dp[i-1][0]+1;
          dp[i][1] = max(max(dp[i-1][0], dp[i-1][1]), max(dp[i-1][2], dp[i-1][3]));

          dp[i][0] = -INF;
          dp[i][2] = -INF;
      }
      else if(up[i]=='X' && down[i]=='X') {
          dp[i][3] = max(max(dp[i-1][0], dp[i-1][1]), max(dp[i-1][2], dp[i-1][3]));
          dp[i][1] = -INF;
          dp[i][0] = -INF;
          dp[i][2] = -INF;
      }
  }

  LL maxi = dp[n-1][0];
  for(int i=1; i<4; i++) {
      maxi = max(maxi, dp[n-1][i]);
  }
  cout << maxi << endl;

  return 0;
}
