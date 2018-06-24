#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp(a, b) make_pair(a,b)
#define FWD(i, a, b) for(int i = a; i < b; i++)
using namespace std;
typedef long long LL;
vi pos;

int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t, k;
  string s;
  cin >> n >> k;
  cin >> s;
  pos.resize(n);
  fill(pos.begin(), pos.end(), 0);
  for(int i=0; i<26; i++) {
    char aha = 'a' + i;
    for(int j=0; j<n; j++) {
      if(s[j]==aha) {
        k--;
        pos[j] = 1;
      }
      if(k==0) break;
    }
    if(k==0) break;
  }
  for(int i=0; i<n; i++) {
    if(pos[i]==0) {
      cout << s[i];
    }
  }
  cout << endl;
  return 0;
}
