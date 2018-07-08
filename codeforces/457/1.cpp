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
  int x;
  string hh, mm;
  cin >> x;
  cin >> hh >> mm;
  LL wynik = 0;
  if(mm[0]=='7' || mm[1]=='7' || hh[0]=='7' || hh[1]=='7') {
      cout << 0 << endl;
  }
  else {
    int mmi, hhi;
    if(hh[0]=='0') {
      hhi = (int)hh[1] - 48;
    }
    else {
      hhi = std::stoi(hh);
    }

    if(mm[0]=='0') {
      mmi = (int)mm[1] - 48;
    }
    else {
      mmi = std::stoi(mm);
    }

    while(true) {
        if(mmi >= x) {
          mmi = (mmi- x)%60;
        } else {
          mmi = (mmi + 60 - x)%60;
          hhi = (hhi + 24 -1)%24;
        }
        wynik += 1;
        if((mmi%10)==7 || (mmi/10)==7 || (hhi%10)==7 || (hhi/10)==7) {
            break;
        }
    }
    cout << wynik << endl;
  }
  return 0;
}
