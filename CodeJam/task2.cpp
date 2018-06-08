#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
int main() {
  std::ios::sync_with_stdio(false);
  ll T, N, a, prev, curr;
  vector<ll> even;
  vector<ll> odd;
  cin >> T;
  for(ll ti=1; ti<=T; ti++) {
      ll index = 0;
      bool OK = true;
      cin >> N;
      for(ll i=0; i<N; i++) {
          cin >> a;
          if(i%2) odd.push_back(a);
          else even.push_back(a);
      }
      sort(odd.begin(), odd.end());
      sort(even.begin(), even.end());
      prev = even[0];
      for(ll i=1; i<N; i++) {
        if(i%2) curr = odd[i/2];
        else curr = even[i/2];
        if(prev>curr) {
          index = i-1;
          OK = false;
          break;
        }
        prev = curr;
      }
      if(OK) cout << "Case #" << ti << ": OK" << endl;
      else cout << "Case #" << ti << ": " << index << endl;
      even.clear();
      odd.clear();
  }
  return 0;
}
