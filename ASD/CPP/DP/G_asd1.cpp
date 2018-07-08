#include <iostream>
#include <algorithm>
using namespace std;

int maxOlives(int n, int **result, int *olives, int *sum)
{
  int x, y, tmp, i, j;
  for(int i=0; i<n; i++)
    result[i][i] = olives[i];

  for(int d=1; d<n; d++)
  {
    for(i=0, j=d; i<n; i++, j=(j+1)%n)
    {
      if(i<j)
      {
        tmp = sum[(j+1)] - sum[i];
        x = tmp - result[(i+1)%n][j];
        y = tmp - result[i][(j+n-1)%n];
        result[i][j] = max(x,y);
      }
      else
      {
        tmp = (sum[n] - sum[i]) + (sum[(j+1)]);
        x = tmp - result[(i+1)%n][j];
        y = tmp - result[i][(j+n-1)%n];
        result[i][j] = max(x,y);
      }
    }
  }
  int wynik = result[0][n-1];
  for(int i=0, d=n-1; i<n; i++, d=(d+1)%n)
     wynik = max(wynik, result[i][d]);
  return wynik;
}

int main() {
  ios_base::sync_with_stdio(0);
  int z, n;
  cin >> z;
  int *sum, *olives, **result;
  for(int zz=0; zz<z; zz++)
  {
    cin >> n;
    sum = new int[n+1];
    olives = new int[n];
    result = new int*[n];
    for(int i=0; i<n; i++)
       result[i] = new int[n];
    sum[0] = 0;
    for(int i=0; i<n; i++)
    {
       cin >> olives[i];
       sum[i+1] = sum[i] + olives[i];
    }
    int res = maxOlives(n, result, olives, sum);

    cout << res << " " << sum[n]-res << endl;
    for(int i=0; i<n; i++)
       delete [] result[i];
    delete [] result;
    delete [] sum;
  }
  return 0;
}
