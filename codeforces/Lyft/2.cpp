#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdint>
#define REP(i, n) for(int i = 0; i < n; i++)
#define BCK(i, n) for(int i = n-1; i >= 0; i--)
#define FWD(i, a, b) for(int i = a; i < b; i++)
using namespace std;

bool isPrime(long long a) {
  for(long long i=2; i<=sqrt(a); i = i+1) {
    if(a%i==0) {
      return false;
    }
  }
  return true;
}

int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t;
  long long a, b;
  long long fn, fm, gn, gm;
  cin >> t;
  while(t--)
  {
    cin >> a >> b;
    if(a-b == 1) {
      if(isPrime(a+b)) cout << "YES" << endl;
      else cout << "NO" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
