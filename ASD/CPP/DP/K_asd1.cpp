#include <iostream>
using namespace std;
const int N = 20;
char chessboard[N][N];
long long DP[1<<N];
bool T[N][N];
int pot[N+1] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576};
long long setTower(int n)
{
  int max = (1<<n);
  DP[0] = 1;
  for (int mask = 1; mask < max; ++mask)
  {
     int len = __builtin_popcount(mask);
     for(int i=0; (mask>>i)>0; i++)
     {
       int tmp = (mask-pot[i]);
       if((mask>>i)%2)
       {
         if(T[len-1][i])
          DP[mask] += DP[tmp];
       }
     }
  }
  return DP[(1<<n)-1];
}
int main()
{
   ios_base::sync_with_stdio(0);
   int n, z;
   cin >> z;
   for(int zz=0; zz<z; zz++)
   {
      cin >> n;
      for(int i=0; i<pot[n]; i++)
      {
        DP[i] = 0;
      }
      for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
          cin >> chessboard[i][j];
          T[i][j] = (chessboard[i][j]=='.')?1:0;
        }
      long long wynik = setTower(n);
      cout << wynik << endl;
   }
   return 0;
}
