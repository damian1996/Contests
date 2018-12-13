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
  unsigned N, result = 0;
  cin >> N;
  unsigned sqr = sqrt(N);
  for(int i=1; i<=sqr; i++) {
        if(N%i == 0) {
            unsigned newN = N/i;
            unsigned sqr2 = sqrt(N/i);
            for(int j=1; j<=(sqr2); j++) {
                if((N-i-j)%(i*j) == 0) {
                    result++;
                }
            }
        }
  }
  cout << result << endl;
  return 0;
}


if(addition[i-1] == 0) {
                    cout << "ONE" << endl;
                    zeroes[i] = (zeroes[i-1] > 0) ? zeroes[i-1] - 1 : 0;
                    addition[i] = 1;
                } else if(allNine(addition[i-1]) == true) { // a co jesli nie ma zer? to chyba jest OK, ale lepiej sprawdz dzbanie
                    cout << "SEC" << endl;
                    zeroes[i] = (zeroes[i-1] > 0) ? zeroes[i-1] - 1 : 0;
                    addition[i] = addition[i-1] + 1;
                } else {
                    cout << "THI" << endl;
                    addition[i] = addition[i-1] + 1;
                    zeroes[i] = zeroes[i-1];
                }