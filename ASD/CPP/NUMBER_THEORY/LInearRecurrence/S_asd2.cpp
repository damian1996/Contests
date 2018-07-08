#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
#define ll long long
#define K 80
#define P 1000
ll factors[K];
ll matrix[K][K];
ll matrix1[K][K];
ll matrix2[K][K];
vector<ll> startElems;
vector<ll> result;
void mmul(int type, int siz)
{
  if(type==0){
    for(int i=0; i<siz; i++)
      for(int j=0; j<siz; j++){
        for(int k=0; k<siz; k++)
          matrix2[i][j] = (matrix2[i][j] + (matrix1[i][k]*matrix1[k][j]))%P;
      }
  } else {
    for(int i=0; i<siz; i++)
      for(int j=0; j<siz; j++){
        for(int k=0; k<siz; k++)
          matrix2[i][j] = (matrix2[i][j] + (matrix[i][k]*matrix1[k][j]))%P;
     }
  }
  for(int i=0; i<siz; i++)
    for(int j=0; j<siz; j++){
      matrix1[i][j] = matrix2[i][j];
      matrix2[i][j] = 0;
    }
}
void fastPot(ll m, ll k)
{
  if(m==0){
    for(int i=0; i<k; i++)
      for(int j=0; j<k; j++)
        matrix1[i][j] = (i==j);
    return;
  }
  if(m==1){
    for(int i=0; i<k; i++)
      for(int j=0; j<k; j++)
        matrix1[i][j] = matrix[i][j];
    return;
  }
  if(m%2==1)
  {
    fastPot(m/2, k);
    mmul(0, k);
    mmul(1, k);
  } else {
    fastPot(m/2, k);
    mmul(0, k);
  }
}
void compute(ll k, ll m)
{
  for(int i=0; i<k; i++)
    for(int j=0; j<k; j++){
      matrix[i][j] = 0;
      matrix1[i][j] = 0;
      matrix2[i][j] = 0;
    }
  for(int i=0; i<k; i++)
    matrix[0][i] = factors[i];
  for(int i=0; i<k-1; i++)
    matrix[i+1][i] = 1;

  fastPot(m-k, k);
  for(int j=0; j<1; j++)
  {
    ll tmp = 0;
    for(int r=0; r<k; r++){
      tmp = (tmp + (matrix1[j][r]*startElems[r]))%P;
    }
    result.push_back(tmp%P);
  }
  cout << setfill('0') << setw(3) << result[0] << endl;
  result.clear();
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    ll z, k, m, el;
    cin >> z;
    while(z--)
    {
        cin >> k >> m;
        for(int i=0; i<k; i++)
          cin >> factors[i];
        for(int i=0; i<k; i++)
        {
          cin >> el;
          startElems.push_back(el);
        }
        if(m<k)
          cout << setfill('0') << setw(3) << startElems[k-m]%P << endl;
        else
          compute(k, m);
        startElems.clear();
    }
    return 0;
}
