#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define N 200000
#define M 500000
vector<int> G[N+2];
vector<int> G2[N+2];
int d[N+1];
int low[N+1];
int sizeSubtree[N+1];
bool visited[N+1];
bool ap[N+1];
int parent[N+1];


void DFSUtil(int x, int &time)
{
  visited[x] = true;
  int children = 0;
  d[x] = time;
  low[x] = time++;
  vector<int>::iterator it;
  for(it=G[x].begin(); it != G[x].end(); ++it)
  {
    if(!visited[*it])
    {
      G2[x].push_back(*it);
      children++;
      parent[*it] = x;
      DFSUtil(*it, time);
      low[x] = min(low[x], low[*it]);
      if (parent[x]==-1 && children > 1)
         ap[x] = true;
      if (parent[x]!=-1 && low[*it] >= d[x])
         ap[x] = true;
      sizeSubtree[x] += sizeSubtree[*it];
    }
    else if(*it!=parent[x])
    {
      low[x] = min(low[x], d[*it]);
    }
  }
}

void DFS(int n)
{
  int time = 1;
  for(int i=1; i<=n; i++)
  {
    if(!visited[i])
    {
      DFSUtil(i, time);
    }
  }
  for(int i=1; i<=n; i++)
  {
    if(ap[i])
    {
      int counter = 0;
      long long result = 0;
      vector<int>::iterator ite;
      for(ite=G2[i].begin(); ite!=G2[i].end(); ++ite)
      {
        if(d[*ite]<d[i])
          continue;
        if(low[*ite]>=d[i])
        {
          long long tmp = sizeSubtree[*ite];
          counter += tmp;
          result += (tmp*(tmp-1));
        }
        else
        {
          continue;
        }
      }
      long long temp = n - counter - 1;
      result += temp*(temp-1);
      cout << result << endl;
    }
    else
    {
      long long y = n-1;
      long long x = y*(n-2);
      cout << x << endl;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  int z, n, m, v, w;
  cin >> z;
  for(int zz=0; zz<z; zz++)
  {
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
      visited[i] = false;
      ap[i] = false;
      G[i].clear();
      G2[i].clear();
      parent[i] = -1;
      sizeSubtree[i] = 1;
    }
    for(int i=0; i<m; i++)
    {
      cin >> v >> w;
      G[v].push_back(w);
      G[w].push_back(v);
    }
    DFS(n);
  }
  return 0;
}
