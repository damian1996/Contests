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
  int n, m, t;
  cin >> n;
  vector<char> digits(n);
  vector<int> digInt(n);
  int sum = 0;
  for(int i=0; i<n; i++) {
    cin >> digits[i];
    digInt[i] = digits[i] - 48;
    sum += digInt[i];
  }
  bool res = true;
  for(int i=0; i<=(sum/2); i++)
  {
      res = true;
      int currSum = 0;
      for(int j=0; j<n; j++)
      {
          if(currSum + digInt[j] < i) {
            currSum += digInt[j];
          }
          else if(currSum + digInt[j] == i) {
              currSum = 0;
          }
          else if(currSum + digInt[j] > i)
          {
              currSum = currSum + digInt[i];
              res = false;
              break;
          }
      }
      if(res && currSum == 0) {
        cout << "YES" << endl;
        return 0;
      }
  }
  cout << "NO" << endl;
  return 0;
}
