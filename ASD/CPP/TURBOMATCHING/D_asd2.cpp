#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define N 1500
#define M 1500
#define K 100

struct skup {
  float x;
  float y;
};
struct node {
  int a, b, sk;
};
vector<node> G[N][M];
skup zboza[K+1];
node mate[N][M];
bool visited[N][M];

bool visit(int i, int j)
{
  if(visited[i][j])
    return false;
  visited[i][j] = true;
  for (node& s : G[i][j])
  {
    if((mate[s.a][s.b].a==-1 && mate[s.a][s.b].b==-1) || (!visited[mate[s.a][s.b].a][mate[s.a][s.b].b] && visit(mate[s.a][s.b].a, mate[s.a][s.b].b)))
    {
      node tmp = {i, j, s.sk};
      mate[i][j] = s;
      mate[s.a][s.b] = tmp;
      return true;
    }
  }
  return false;
}
bool findPaths(int m, int n)
{
  bool found = false;
  for(int i=0; i<m; i++)
  {
    for(int j=0; j<n; j++)
    {
      visited[i][j] = false;
    }
  }
  for(int i=0; i<m; i++)
  {
    for(int j=0; j<n; j++)
    {
      if(!visited[i][j] && mate[i][j].a==-1 && mate[i][j].b==-1)
      {
        if(visit(i, j))
        {
          found = true;
        }
      }
    }
  }
  return found;
}
void turboMatching(int m, int n)
{
  while(1)
  {
    bool test = findPaths(m, n);
    if(!test)
      return;
  }
}
void result(int m, int n)
{
  for(int i=0; i<m; i++)
  {
    for(int j=0; j<n; j++)
    {
      if(mate[i][j].a==-1 && mate[i][j].b==-1)
      {
        cout << "NIE" << endl;
        return;
      }
    }
  }
  cout << "TAK" << endl;
  for(int i=0; i<m; i++)
  {
    for(int j=0; j<n; j++)
    {
      cout << mate[i][j].sk << " ";
    }
    cout << endl;
  }
  return;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int z, n, m, k, p1, r1;
  float x1, x2, y1, y2, p, r;
  node tmp;
  cin >> z;
  for(int zz=0; zz<z; zz++)
  {
    cin >> m >> n >> k;
    for(int i=0; i<m; i++)
    {
      for(int j=0; j<n; j++)
      {
        G[i][j].clear();
        mate[i][j].a = -1;
        mate[i][j].b = -1;
      }
    }
    for(int i=1; i<=k; i++)
    {
      cin >> zboza[i].x >> zboza[i].y;
    }
    for(int j=0; j<m; j++)
    {
      for(int l=0; l<n; l++)
      {
        for(int i=1; i<=k; i++)
        {
          x1=j+0.5, x2=l+0.5;
          y1=zboza[i].x-x1, y2=zboza[i].y-x2;
          p=x1+2*y1, r=x2+2*y2;
          if(0<=p && p<m && 0<=r && r<n)
          {
            p1 = p, r1 = r;
            tmp = {p1, r1, i};
            G[j][l].push_back(tmp);
          }
        }
      }
    }
    turboMatching(m, n);
    result(m, n);
  }
  return 0;
}
