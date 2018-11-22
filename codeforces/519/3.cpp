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

string reverseStr(string str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
    return str;
}

int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t;
  string s;
  cin >> s;
  n = s.size();
  vector<int> resBest(n), resWorst(n);
  string theBest = s.substr(0, 1), theWorst = s.substr(0, 1);
  resBest[0] = 0;
  resWorst[0] = 0;
  for(int i=1; i<n; i++)
  {
      if(s[i] == 'a')
      {
          theWorst += "a";
          resWorst[i] = 0;
          theBest = reverseStr(theWorst);
          for(int j=0; j<i; j++) resBest[j] = resWorst[j];
          resBest[i] = 1;
      }
      else
      {
          theBest += "b";
          theWorst = reverseStr(theBest);
          for(int j=0; j<i; j++) resWorst[j] = resBest[j];
          resWorst[i] = 1;
          resBest[i] = 0;
      }
  }
  for(int i=0; i<n; i++) cout << resBest[i] << " \n"[i==n-1];
  return 0;
}
