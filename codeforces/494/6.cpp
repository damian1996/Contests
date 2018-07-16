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

bool eq[302][302];
int dp[302][302];
vector<string> in;

bool equally(int i, int j) {
    return (in[i].compare(in[j]) == 0) ? true : false;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, t;
    cin >> n;
    in.resize(n+1);
    int sizeOfText = n-1;
    for(int i=1; i<=n; i++) {
        cin >> in[i];
        sizeOfText += in[i].size();
    }
    for(int i=1; i<n; i++) {
        for(int j=i+1; j<=n; j++) {
            if(equally(i, j)) {
                eq[i][j] = true;
                eq[j][i] = true;
            }
        }
    }
    for(int i=n; i>0; i--) {
          for(int j=n; j>0; j--) {
              if(i!=j) {
                  if(eq[i][j]) {
                      if(i < n && j < n) {
                          dp[i][j] = dp[i+1][j+1] + 1;
                      } else {
                          dp[i][j] = 1;
                      }
                  }
              }
          }
    }
    int res = sizeOfText, cnt, sumSizes, ans;
    for(int i=1; i<=n; i++) {
        int sumSizes = 0;
        for(int j=1; (i+j)<=n; j++) {
            sumSizes += in[i+j-1].size();
            cnt = 1;
            for(int k = i+j; k<=n;) {
                if(dp[i][k]>=j) {
                    ++cnt;
                    k += j;
                } else {
                    k++;
                }
            }
            ans = sizeOfText - cnt*sumSizes + j*cnt - cnt*(j-1);
            if(cnt>1 && res > ans) {
              res = ans;
            }
        }
    }
    cout << res << endl;
    return 0;
}
