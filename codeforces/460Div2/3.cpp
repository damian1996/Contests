#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define FWD(i, a, b) for(int i = a; i < b; i++)
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp(a, b) make_pair(a,b)
using namespace std;
typedef long long ll;

int main() {
  std::ios::sync_with_stdio(false);
  ll m, n, k;
  cin >> n >> m >> k;
  char seats[n][m];
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> seats[i][j];
    }
  }
  ll ways = 0;
  for(int i=0; i<n; i++) {
    int inRow = 0;
    for(int j=0; j<m; j++) {
      if(seats[i][j]=='.') {
        if((inRow+1) == k) ways++;
        else inRow++;
      }
      else inRow = 0;
    }
  }
  if(k!=1) {
    for(int i=0; i<m; i++) {
      int inColumn = 0;
      for(int j=0; j<n; j++) {
        if(seats[j][i]=='.') {
          if((inColumn+1) == k) ways++;
          else inColumn++;
        }
        else inColumn = 0;
      }
    }
  }
  cout << ways << endl;
  return 0;
}
