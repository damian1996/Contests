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
  int A, B, C, N;
  cin >> A >> B >> C >> N;
  int wynik = A + B - C;
  if((N-wynik >= 1) && (A<=N) && B<=N && C<=N && A>=C && B>=C && (A+B)>=C) {
    cout << N - wynik << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
