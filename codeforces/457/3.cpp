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
const int maxWeight = 1e9;

bool pierwsza(int n)
{
    if (n<2) return false;
    for (int j=2; j*j<=n; j++)
    {
        if (n%j==0) return false;
    }
    return true;
}


int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t;
  cin >> n >> m;
  int nextPrime;
  bool end = false;
  if(pierwsza(n-1)) {
      nextPrime = n-1;
      cout << nextPrime << " " << nextPrime << endl;
      for(int i=1; i<n; i++) {
        cout << i << " " << i+1 << " " << 1 << endl;
        m--;
      }
      for(int i=1; i<n; i++) {
          for(int j=i+2; j<=n; j++) {
              if(m<=0) break;
              cout << i << " " << j << " " << maxWeight << endl;
              m--;
          }
          if(m<=0) break;
      }
  } else {
      int nextPrime;
      for(int k=n;;k++) {
          if(pierwsza(k)) {
              nextPrime = k;
              break;
          }
      }
      cout << nextPrime << " " << nextPrime << endl;
      cout << 1 << " " << 2 << " " << (nextPrime - (n-1) + 1) << endl;
      nextPrime = nextPrime - (nextPrime - (n-1) + 1);
      m--;
      for(int i=2; i<n; i++) {
        cout << i << " " << i+1 << " " << 1 << endl;
        m--;
      }
      for(int i=1; i<n; i++) {
          for(int j=i+2; j<=n; j++) {
              if(m<=0) break;
              cout << i << " " << j << " " << maxWeight << endl;
              m--;
          }
          if(m<=0) break;
      }
  }
  return 0;
}
