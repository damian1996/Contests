#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define N 100
#define M 100

struct node {
  int a, b;
};
vector<node> G[N][M];
node mate[N][M];
bool visited[N][M];
char in[N][M];
bool visit(int i, int j)
{
  if(visited[i][j])
    return false;
  visited[i][j] = true;
  for (node& s : G[i][j])
  {
    if((mate[s.a][s.b].a==-1 && mate[s.a][s.b].b==-1) || (!visited[mate[s.a][s.b].a][mate[s.a][s.b].b] && visit(mate[s.a][s.b].a, mate[s.a][s.b].b)))
    {
      node tmp = {i, j};
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
      if(in[i][j]=='X')
        cout << "X";
      else
      {
        if(visited[i][j])
          cout << "K";
        else
          cout << "W";
      }
    }
    cout << endl;
  }
  cout << endl;
  return;
}
void createEdge(int a, int b, int i, int j, int m, int n)
{
  node tmp = {i, j};
  if(in[i][j]!='X' && 0<=i && i<m && 0<=j && j<n)
  {
    G[a][b].push_back(tmp);
  }
}
int main()
{
  std::ios_base::sync_with_stdio(false);
  int z, n, m, p1, r1;
  cin >> z;
  for(int zz=0; zz<z; zz++)
  {
    cin >> m >> n;
    for(int i=0; i<m; i++)
    {
      for(int j=0; j<n; j++)
      {
        G[i][j].clear();
        mate[i][j].a = -1;
        mate[i][j].b = -1;
      }
    }
    for(int i=0; i<m; i++)
      for(int j=0; j<n; j++)
        cin >> in[i][j];

    for(int j=0; j<m; j++)
    {
      for(int l=0; l<n; l++)
      {
        if(in[j][l]=='X')
          continue;
        createEdge(j, l, j+1, l, m, n);
        createEdge(j, l, j-1, l, m, n);
        createEdge(j, l, j, l+1, m, n);
        createEdge(j, l, j, l-1, m, n);
      }
    }
    turboMatching(m, n);
    result(m, n);
  }
  return 0;
}
