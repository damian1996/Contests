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
vector<pair<int, int> > sq[2];
int A[202][202];

bool intersect() {
    sort(sq[0].begin(), sq[0].end());
    sort(sq[1].begin(), sq[1].end());
    for(int i=0; i<4; i++) {
        sq[0][i].st += 100;
        sq[0][i].nd += 100;
        sq[1][i].st += 100;
        sq[1][i].nd += 100;
    }
    for(int i=sq[0][0].st; i<=sq[0][3].st; i++) {
        for(int j=sq[0][0].nd; j<=sq[0][3].nd; j++) {
            a[i][j] = 1;
        }
    }
    return false;
}

int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t;
  for(int i=0; i<2; i++) {
    sq[i].resize(4);
    for(int j=0; j<4; j++) {
      cin >> sq[i][j].st;
      cin >> sq[i][j].nd;
    }
  }

  if(intersect()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
