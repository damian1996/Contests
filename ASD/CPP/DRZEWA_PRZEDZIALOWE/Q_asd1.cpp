#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 65536
#define INF 60000
struct intv
{
  int psg; // pasazerowie
  int maxP; // max poddrzewa
};
struct intv railways[2*MAX];

void addCorrect(int v, int l)
{
     railways[v].psg += l;
     railways[v].maxP += l;
     while (v>0) // v>1 ??
     {
        v = v/2;
        railways[v].maxP = max(railways[2*v].maxP, railways[2*v+1].maxP) + railways[v].psg;
    }
}
void addToIntv(int p, int k, int l, int n)
{
  int xp = p+n-1, xk = k+n-1;
  addCorrect(xp, l);
  if (xp<xk) addCorrect(xk, l);
  while (xp/2 != xk/2)
  {
     if (xp%2==0) addCorrect(xp+1, l);
     if (xk%2==1) addCorrect(xk-1, l);
     xp = xp/2;
     xk = xk/2;
  }
}
int query(int p, int k, int l, int n)
{
  int xp = p+n-1, xk = k+n-1;
  int first, second=0;
  first = railways[xp].psg;
  if (xp<xk)
    second = railways[xk].psg;
  while (xp/2 != xk/2)
  {
     if (xp%2==0)
      first = max(first, railways[xp+1].maxP);
     if (xk%2==1)
      second = max(second, railways[xk-1].maxP);
     xp = xp/2;
     xk = xk/2;
     first += railways[xp].psg;
     second += railways[xk].psg;
  }
  int result = max(first, second);
  while(xp>0) // 1
  {
    xp = xp/2;
    result += railways[xp].psg;
  }
  return result;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    for(int i=0; i<2*MAX; i++)
    {
      railways[i].psg = 0;
      railways[i].maxP = 0;
    }
    int sets, n, m, q, p, k, l, power;
    int pot[17];
    pot[0] = 1;
    for(int i=1; i<17; i++)
    {
        pot[i] = pot[i-1]*2;
    }
    cin >> sets;
    for(int z=0; z<sets; z++)
    {
      cin >> n >> m >> q;
      for(int i=1; i<17; i++)
      {
          if(n>pot[i-1] && n<=pot[i])
          {
              power = pot[i];
              break;
          }
      }
      for(int i=0; i<q; i++)
      {
        cin >> p >> k >> l;
        int temp = query(p, k-1, l, power);
        if((temp+l) <= m)
        {
          cout << "T" << endl;
          addToIntv(p, k-1, l, power);
        }
        else
          cout << "N" << endl;
      }

      for(int i=0; i<2*power; i++)
      {
        railways[i].psg = 0;
        railways[i].maxP = 0;
      }
    }
    return 0;
}
