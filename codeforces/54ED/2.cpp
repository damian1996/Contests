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


bool isPrime(int num)
{
    bool prime = true;

    if(num < 2)
        prime = true;
    for (int i = 2; i < (int)sqrt(num) + 1; i++)
        if (num % i == 0)
            prime = false;
    return prime;
}

int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t;
  cin >> n;
  int subtr = 0;
  unordered_map<int, int> pr;
  pr[1] = 0; pr[2] = 1; pr[3] = 1;
  for(int i=4; i<10e5+1; i++) {
      if(isPrime(i)) pr[i] = 1;
      else pr[i] = 0;
  }
  while(n!=0) {
      if(pr[n]) {}
      d = primeDivisor(n);
      n = n - d;
      subtr++;
  }
  cout << subtr << endl;
  return 0;
}
