#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
#define N 50
#define M 50
const double eps = 1e-9;
const double INFTY = 100000001;
double arr[M+1][N+M+1];
int base[M+1];

void changeBase(int in, int out, int n, int m)
{
  double alpha = arr[out][in];
  arr[out][in] = 0;
  arr[out][base[out]] = -1;
  for(int i=0; i<n+m+1; i++)
      arr[out][i] /= (-alpha);

  for(int i=0; i<=m; i++)
  {
    if(i==out) continue;
    double beta = arr[i][in];
    arr[i][in] = 0;
    for(int j=0; j<=n+m; j++)
      arr[i][j] = arr[i][j] + beta*arr[out][j];
  }
  base[out] = in;
}

bool simplex(int n, int m)
{
  while(true)
  {
    int counter = 0;
    for(int i=1; i<=n+m; i++)
    {
      if(arr[0][i]>eps)
      {
        counter++;
        int cnt = 0;
        for(int j=1; j<=m; j++)
          if(arr[j][i]>-eps)
            cnt++;
        if(cnt == m) return false;

        double minValue = INFTY;
        int idx = 0;

        for(int j=1; j<=m; j++)
        {
            if(arr[j][i] >-eps) continue;
          if(minValue - (arr[j][0]/(-arr[j][i])) > eps)
          {
            minValue = arr[j][0]/(-arr[j][i]);
            idx = j;
          }
        }
        changeBase(i, idx, n, m);
      }
    }
    if(counter==0) return true;
  }
  return true;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int z, n, m;
  bool res;
  cin >> z;
  while(z--)
  {
    cin >> n >> m;
    for(int i=0; i<m+1; i++)
      for(int j=0; j<m+n+1; j++)
        arr[i][j] = 0;
    for(int i=1; i<=n; i++)
      cin >> arr[0][i];
    for(int i=1; i<=m; i++)
      base[i] = n+i;
    for(int i=1; i<=m; i++)
    {
      for(int j=1; j<=n; j++)
      {
        cin >> arr[i][j];
        arr[i][j] = -arr[i][j];
      }
      cin >> arr[i][0];
    }

    res = simplex(n, m);

    if(!res)
      cout << "UNBOUNDED" << endl;
    else
    {
      cout << fixed << arr[0][0] << endl;
      for(int i=1; i<=n; i++)
      {
        cout << "x_" << i << " = ";
        bool found = false;
        for(int k=1; k<=m; k++)
        {
           if(base[k]==i)
           {
             cout << fixed << arr[k][0] << endl;
             found = true;
             break;
           }
        }
        if(!found)
          cout << fixed << 0 << endl;
      }
    }
  }
  return 0;
}
