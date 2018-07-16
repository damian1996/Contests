#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define BCK(i, n) for(int i = n-1; i >= 0; i--)
#define FWD(i, a, b) for(int i = a; i < b; i++)
#define pb push_back
#define st first
#define nd second
#define vi vector<int>
#define vll vector<long long>
#define pi pair<int, int>
#define pll pair<long long, long long>
#define vpi vector<pi>
#define vpll vector<pll>
#define mp(a, b) make_pair(a,b)
using namespace std;
typedef long long LL;
typedef double ld;
const LL p = 1000000007;


int main() {
  std::ios::sync_with_stdio(false);
  LL n, m, t, k;
  cin >> n >> k;
  vector<long long> prof(n);
  for(int i=0; i<n; i++)
      cin >> prof[i];
  vector<pair<long long, long long>> maxes;
  LL maxii = 0;
  for(LL i=0; i<k; i++) {
    maxii += prof[i];
    maxes.pb(mp(prof[i], i));
  }
  for(int i=k; i<n; i++) {
      LL maxi = maxii;
      LL maxPos = i, maxSum = maxi;
      for(int j=k-1; j>=0; j--) {
          LL tmpMaxi = maxi - maxes[j].st;
          if((prof[i] + tmpMaxi) > maxSum) {
              maxSum = prof[i] + tmpMaxi;
              maxPos = j;
          }
      }
      if(maxPos < i) {
          for(int j=maxPos; j<k-1; j++) {
              maxes[j].st = maxes[j+1].st;
              maxes[j].nd = maxes[j+1].nd;
          }
          maxes[k-1].st = prof[i];
          maxes[k-1].nd = i;
          maxii = maxSum;
      }
  }
  cout << maxii << endl;
  if(k==1) {
    cout <<  n;
  } else if(k==2) {
      cout << maxes[1].nd << " ";
      cout << n - maxes[1].nd << " ";
  } else {
    cout << maxes[1].nd << " ";
    for(int i=1; i<k-1; i++) {
        cout << maxes[i+1].nd - maxes[i].nd << " ";
    }
    cout << n - maxes[k-1].nd << " ";
  }
  cout << endl;
  return 0;
}
