#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp(a, b) make_pair(a,b)
#define FWD(i, a, b) for(int i = a; i < b; i++)
using namespace std;
typedef long long LL;

bool vasPet() {


  if(vas >= pet) return true;
  return false;
}

int main() {
  std::ios::sync_with_stdio(false);
  LL n, m, t;
  cin >> n;

  LL low = 1, high = n+1, mid, leftNote;
  LL vas = 0, pet = 0, k;
  while(low <= high) {
      mid = (low+high)/2;

      vas = 0, pet = 0, k = n;
      while(k>0) {
          if(k>=mid) {
            vas += mid;
            k -= mid;
            pet += (k/10);
            k -= (k/10);
          }
          else if(k<mid) {
            vas += k;
            k = 0;
          }
      }

      if(vas >= pet) {
        high = mid - 1;
      }
      else {
        low = mid + 1;
      }
  }
  cout << mid << endl;
  return 0;
}
