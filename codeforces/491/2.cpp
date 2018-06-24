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
  int n, m, t;
  cin >> n;
  vi grades;
  grades.resize(n);
  float sum = 0;
  for(int i=0; i<n; i++) {
    cin >> grades[i];
    sum += (float) grades[i];
  }
  sort(grades.begin(), grades.end());
  if(sum/(float)n >= 4.5) {
    cout << 0 << endl;
  }
  else {
    for(int i=0; i<n; i++) {
      sum -= ((float) grades[i]);
      sum += 5.0;
      if(sum/(float)n >= 4.5) {
        cout << i+1 << endl;
        break;
      }
    }
  }
  return 0;
}
