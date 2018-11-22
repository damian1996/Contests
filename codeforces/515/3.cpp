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
const int N = 2*100000+1;
vector<int> dq(2*N);
vector<int> indeksy(N);
int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t, q, id;
  char c;
  cin >> q;
  m = N;
  int beg, fin;
  for(int i=0; i<q; i++) {
      cin >> c;
      cin >> id;
      if(i==0) {
          dq[m] = id;
          indeksy[id] = m;
          beg = m;
          fin = m;
      } else {
          if(c == 'L') {
              dq[--beg] = id;
              indeksy[id] = beg;
          } else if (c == 'R') {
              dq[++fin] = id;
              indeksy[id] = fin;
          } else {
              cout << min(indeksy[id]-beg, fin-indeksy[id]) << endl;
          }
      }
  }
  return 0;
}
