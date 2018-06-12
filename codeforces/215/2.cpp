#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp(a, b) make_pair(a,b)
#define FWD(i, a, b) for(int i = a; i < b; i++)
using namespace std;
typedef long long LL;
int a[100002], b[100002], c[100002];

int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t, el;
  cin >> n >> m; 
  for(int i=1; i<=n; i++) {
  	cin >> a[i];
  }
  b[n] = 1;
  c[a[n]] = 1; 
  for(int i=n-1; i>=1; i--) {
	if(c[a[i]] == 1) {
	    b[i] = b[i+1];
	}
  	else {
	    b[i] = b[i+1] + 1;
	    c[a[i]] = 1;
	}
  }
  for(int j=0; j<m; j++) {
	cin >> el;
	cout << b[el] << endl;
  }
  return 0;
}
