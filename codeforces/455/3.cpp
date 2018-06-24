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

int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t;
  cin >> n;
  vector<char> vec;
  vec.resize(n);
  for(int i=0; i<n; i++) {
      cin >> vec[i];
  }
  LL wynik = 1;
  char prev;
  LL countF = 0;
  LL countFAll = 0;
  for(int i=0; i<n; i++) {
    if(vec[i]=='s') {
      if(prev=='s') {
          wynik = (wynik * countFAll)%p;
      }
      prev = 's';
    }
    else if(vec[i]=='f') {
      if(prev=='s') {
        wynik = (wynik * countFAll)%p;
      }
      countFAll++;
      prev = 'f';
    }
  }
  cout << wynik << endl;
  return 0;
}
