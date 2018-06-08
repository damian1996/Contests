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
  cin >> n >> k;
  vll seq;
  REP(i, n) {
     cin >> ai;
     seq.pb(ai);
  }
  sort(seq.begin(), seq.end());
  ll j = 0;


  if(k==0) {
    if(seq[0]>1) {
      cout << seq[0]-1 << endl;
    } else {
      cout << -1 << endl;
    }
  } else {
     FWD(i, 0, n) {
        j += 1;
        if(j==k) {
          if(i+1<n && seq[i+1]==seq[i]) {
            cout << -1 << endl;
          } else {
              cout << seq[i] << endl;
          }
          break;
        }
     }
  }
  return 0;
}
