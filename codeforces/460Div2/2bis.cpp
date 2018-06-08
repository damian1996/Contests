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
  ll n, maxi = 0;
  string s, maxStr;
  cin >> n;
  cin >> s;
  map<string,long long> m;
  FWD(i, 0, n-1)  {
    string str = s.substr(i, 2);
    auto it = m.find(str);
    if (it != m.end()) {
      it->second += 1;
    } else {
      m[str] = 1;
    }
  }

  for(auto it : m) {
    if(it.second>maxi) {
      maxi = it.second;
      maxStr = it.first;
    }
  }
  cout << maxStr << endl;
  return 0;
}
