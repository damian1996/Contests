#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp(a, b) make_pair(a,b)
#define FWD(i, a, b) for(int i = a; i < b; i++)
using namespace std;
typedef long long LL;

int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t, p;
  string s;
  cin >> n >> p;
  cin >> s;

  bool popsute = false;
  for(int i=0; i<n-p; i++) {
    if(s[i]=='.' && s[i+p]=='.') {
      // mozna popsuc
      s[i] = '1';
      s[i+p] = '0';
      popsute = true;
    }
    else if(s[i]=='.' && s[i+p]!='.') {
      if(s[i+p]=='1') s[i] = '0';
      else if(s[i+p]=='0') s[i] = '1';
      popsute = true;
    }
    else if(s[i+p]=='.' && s[i]!='.') {
      if(s[i]=='1') s[i+p] = '0';
      else if(s[i]=='0') s[i+p] = '1';
      popsute = true;
    }
    else {
      if((s[i]=='0' && s[i+p]=='1') || (s[i]=='1' && s[i+p]=='0')) {
          popsute = true;
      }
    }
  }

  if(popsute) {
    for(int i=0; i<n; i++) {
      if(s[i] == '.') s[i] = '0';
    }
    cout << s << endl;
  }
  else {
    cout << "No" << endl;
  }
  return 0;
}
