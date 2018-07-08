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
  int n, m, t, a, b, x;
  cin >> a >> b >> x;
  string s(a+b, '-');
  int sum = 0;
  bool amore = true;
  if(b>a) {
    amore = false;
  }
  if(x==1) {
      while((a--)>0) {
        s[sum++] = '0';
      }
      while((b--)>0) {
        s[sum++] = '1';
      }
  }
  else {
    if(amore) {s[sum++] = '0'; a--; }
    else { s[sum++] = '1'; b--; }

    while(x>1) {
      if(sum%2==0) {
        if(amore) {
          s[sum] = '0';
          a--;
        }
        else {
          s[sum] = '1';
          b--;
        }
      }
      else {
        if(amore) {
          s[sum] = '1';
          b--;
        }
        else {
          s[sum] = '0';
          a--;
        }
      }
      x--;
      sum++;
    }
    if(sum%2==0) {
        if(amore) {
            while(b--) s[sum++] = '1';
            while(a--) s[sum++] = '0';
        }
        else {
          while(a--) s[sum++] = '0';
          while(b--) s[sum++] = '1';
        }
    }
    else {
      if(amore) {
        while(a--) s[sum++] = '0';
        while(b--) s[sum++] = '1';
      }
      else {
        while(b--) s[sum++] = '1';
        while(a--) s[sum++] = '0';
      }
    }
  }

  cout << s << endl;
  return 0;
}
