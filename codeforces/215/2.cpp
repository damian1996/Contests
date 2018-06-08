#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp(a, b) make_pair(a,b)
#define FWD(i, a, b) for(int i = a; i < b; i++)
using namespace std;
typedef long long LL;
int a[100002], b[100002];

int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t;
  cin >> n >> m; 
  for(int i=1; i<=n; i++) {
  	cin >> a[i];
  	b[a[i]] = i;
  }
  
  for(int j=0; j<m; j++) {
	int wynik = 0;	
	
	cout << wynik << endl;
  }
  return 0;
}
