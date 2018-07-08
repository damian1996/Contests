#include <cstdio>
#include <vector>
#include <cstring>
const double INF=100000.0;
using namespace std;

struct node
{
  int b;
  double w;
};

vector<node> G[677];
double D[677];

bool BF(double m, int n)
{
  for (int i=1; i<676; i++)
  {
    for(int j=1; j<=676; j++)
    {
      vector<node>::iterator it;
      for(it=G[j].begin(); it!=G[j].end(); ++it)
      {
        int v = (*it).b;
        double w = (m - (*it).w);
        if(D[j]+w < D[v])
        {
          D[v] = D[j]+w;
        }
      }
    }
  }
  for(int j=1; j<=676; j++)
  {
    vector<node>::iterator it;
    for(it=G[j].begin(); it!=G[j].end(); ++it)
    {
      int v = (*it).b;
      double w = m - (*it).w;
      if(D[j]+w < D[v]) // D[j]!=INF &&
      {
        return false;
      }
    }
  }
  return true;
}

int main()
{
  int z, n, siz;
  double l, p, m;
  char word[1002];
  scanf("%d", &z);

  for(int zz=0; zz<z; zz++)
  {
    for(int i=1; i<677; i++)
    {
      G[i].clear();
      D[i] = INF;
      node tmp = {i, 0};
      G[0].push_back(tmp);
    }
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
      scanf("%s", word);
      siz = strlen(word);
      int c1 = word[0]-'a'+1, c2 = word[1]-'a'+1;
      int n1 = word[siz-2]-'a'+1, n2 = word[siz-1]-'a'+1;
      node tmp = {(26*(n1-1)+n2), siz};
      G[26*(c1-1)+c2].push_back(tmp);
    }
    int counter = 0;
    l=0;
    p=1001;
    int iter=0;
    //while((p-l)>10e-10)
    while(iter<24)
    {
      //printf("%f %f \n", l, p);
      m = (l+p)/2;
      if(!BF(m, n)) {
        counter++;
        l = m;
      }
      else p = m;
      iter++;
    }
    if(counter==0 || m<1) printf("NIE\n");
    else printf("%.4f\n", m);
  }
  return 0;
}
