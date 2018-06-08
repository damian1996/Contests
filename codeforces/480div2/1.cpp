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
  ll n, k, ai;
  ll links = 0;
  ll pearls = 0;
  string s;
  cin >> s;
  for(int i=0; i<s.size(); i++) {
    if(s[i]=='-') {
      links++;
    } else {
      pearls++;
    }
  }
  if(pearls == 0 || links == 0) {
    cout << "YES" << endl;
  } else {
    if(links>=pearls) {
      if(links%pearls==0)
        cout << "YES" << endl;
      else if(links%pearls!=0)
        cout << "NO" << endl;
    } else if(links < pearls) {
      cout << "NO" << endl;
    }
  }
  return 0;
}
