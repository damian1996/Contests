#include <iostream>
#include <algorithm>
using namespace std;
int main() {
      ios_base::sync_with_stdio(0);
    int z, n, b, M;
    int *a;
    int *c;
    long long *dp;
    cin >> z;
    for(int zz=0; zz<z; zz++)
    {
      cin >> n;
      dp = new long long[n+1];
      a = new int[n+1];
      c = new int[n+1];
      dp[0] = 0;
      a[0] = 0;
      c[0] = 0;
      for(int i=1; i<=n; i++)
      {
        cin >> a[i] >> c[i];
      }
      cin >> M >> b;
      int i=1;
      if(c[i]<b)
        dp[i] = dp[i-1] + c[i];
      else
      {
        dp[i] = b;
      }
      int j=1;
      for(int i=2; i<=n; i++)
      {
        j = i-1;
        while((a[i]-a[j])<=M && j>0)
        {
           j--;
        }
        long long L = dp[j] + b;
        long long R = dp[i-1] + c[i];
        dp[i] = min(L, R);
      }
      cout << dp[n] << endl;
      delete [] dp;
      delete [] c;
      delete [] a;
    }
 return 0;
}
