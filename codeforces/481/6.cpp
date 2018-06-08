#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define FWD(i, a, b) for(int i = a; i < b; i++)
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define pi pair<int, int>
#define mp(a, b) make_pair(a,b)
#define vpll vector<pair<long long, long long>>
using namespace std;
typedef long long ll;
const ll N = 1e9;

int main() {
  std::ios::sync_with_stdio(false);
  ll n, k, k1, k2;
  cin >> n >> k;
  vll skills(n);
  vpll argues(k);
  REP(i, n)
    cin >> skills[i];

  REP(i, k) {
    cin >> k1 >> k2;
    argues[i] = mp(k1, k2);
  }
  return 0;
}
