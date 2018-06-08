#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define FWD(i, a, b) for(int i = a; i < b; i++)
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define pi pair<int, int>
#define mp(a, b) make_pair(a,b)
using namespace std;
typedef long long ll;
const ll N = 1e9;


int main() {
  std::ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  char tab[4+1][n+1];
  for(int i=1; i<=4; i++)
    for(int j=1; j<=n; j++)
      tab[i][j] = '.';

  if(k%2==0) {
      for(int i=0; i<k/2; i++) {
        tab[2][2+i] = '#';
        tab[3][2+i] = '#';
      }
      cout << "YES" << endl;
      for(int i=1; i<=4; i++) {
        for(int j=1; j<=n; j++) {
          cout << tab[i][j];
        }
        cout << endl;
      }
  } else {
      if(k<=(n-2)) {
          int tmp = n/2+1;
          tab[2][n/2+1] = '#';
          int ilosc = k/2, left = tmp-1, right = tmp+1;
          while(ilosc>0) {
            tab[2][left--] = '#';
            tab[2][right++] = '#';
            ilosc--;
          }
      }
      else {
          for(int i=2; i<n; i++)
              tab[2][i] = '#';
          int tmp = n/2+1;
          int ilosc = (k-(n-2))/2, left = tmp-1, right = tmp+1;
          while(ilosc>0) {
            tab[3][left--] = '#';
            tab[3][right++] = '#';
            ilosc--;
          }
      }
      cout << "YES" << endl;
      for(int i=1; i<=4; i++) {
        for(int j=1; j<=n; j++) {
          cout << tab[i][j];
        }
        cout << endl;
      }
  }

  return 0;
}
