#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100000;
struct person
{
  int start;
  int end;
  int number;
};
struct moments
{
  int nr;
  char pork;
  int tm;
  bool operator< (const moments &c2)
  {
    if(tm < c2.tm)
      return true;
    else if(tm==c2.tm)
    {
      if(pork=='K' && c2.pork=='P')
        return false;
      else if((pork=='K' && c2.pork=='K') || (pork=='P' && c2.pork=='P'))
        return false;
      else
              return true;
    }
    else
      return false;
  }
};
struct person photos[N+1];
struct moments element[2*N];
long long result[N+1];

int main()
{
  ios_base::sync_with_stdio(false);
  int z, n;
  long long prefiks;
  cin >> z;
  for(int zz=0; zz<z; zz++)
  {
    cin >> n;
    for(int i=0; i<n; i++)
    {
      cin >> photos[i].start >> photos[i].end >> photos[i].number;
      element[2*i].nr = i;
      element[2*i].pork = 'P';
      element[2*i].tm = photos[i].start;
      element[2*i+1].nr = i;
      element[2*i+1].pork = 'K';
      element[2*i+1].tm = photos[i].end;
    }
    sort(element, element+2*n);
    for(int i=0; i<n; i++)
      result[i] = 0;
    prefiks = 0;
    for(int i=0; i<2*n; i++)
    {
      if(element[i].pork=='P')
      {
        result[element[i].nr] = prefiks;
      }
      else
      {
        int test = prefiks - result[element[i].nr];
        int test2 = photos[element[i].nr].number - test;
        if(test2>0)
          prefiks+=test2;
      }
    }
    cout << prefiks << endl;
  }
  return 0;
}
