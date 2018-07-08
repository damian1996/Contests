#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define N 8000
#define M 30000
#define INFTY 240000002

struct node {
  int capacity;
  int flow;
  int v;
};

vector<node> G[2*N+1];
bool visited[2*N+1];
vector<int> result;
int P[2*N+1];

bool BFS(int n, int u1, int v1)
{
  vector<node>::iterator it;
  queue<int> Q;
  Q.push(u1);
  while(!Q.empty())
  {
    int el = Q.front();
    Q.pop();
    for(it=G[el].begin(); it!=G[el].end(); ++it)
    {
      if(((*it).capacity-(*it).flow)>0 && P[(*it).v]==-1)
      {
        P[(*it).v] = el;
        if((*it).v!=v1)
        {
          Q.push((*it).v);
        }
        else
        {
          int v = (*it).v;
          while(true)
          {
            vector<node>::iterator ite;
            int temp = 0;
            for(ite=G[P[v]].begin(); ite!=G[P[v]].end(); ++ite)
            {
              if((*ite).v == v)
              {
                (*ite).flow += 1;
                temp = (*ite).flow;
                break;
              }
            }
            for(ite=G[v].begin(); ite!=G[v].end(); ++ite)
            {
              if((*ite).v == P[v])
              {
                (*ite).flow = -temp;
                break;
              }
            }
            if(P[v]==u1)
              break;
            v = P[v];
          }
          return true;
        }
      }
    }
  }
  return false;
}

void checkResGraph(int i, int n)
{
  visited[i] = true;
  vector<node>::iterator it;
  for(it=G[i].begin(); it != G[i].end(); ++it)
  {
    if(((*it).capacity - (*it).flow) > 0 && !visited[(*it).v])
    {
      checkResGraph((*it).v, n);
    }
  }
}

void EdKarp(int m, int n, int u1, int v1)
{
  while(true)
  {
    for(int i=1; i<=2*n; i++)
      P[i] = -1;

    bool test = BFS(n, u1, v1);
    if(test)
      continue;
    else
    {
      checkResGraph(u1, n);
      int numbersVertex = 0;
      for(int i=1; i<=2*n; i++)
      {
        vector<node>::iterator it;
        for(it=G[i].begin(); it!=G[i].end(); ++it)
        {
          if(visited[i]==true && visited[(*it).v]==false && (*it).capacity==1)
          {
            bool tes = false;
            vector<int>::iterator itt;
            for(itt=result.begin(); itt!=result.end(); ++itt)
            {
              if((*itt)==(*it).v/2)
              {
                tes = true;
                break;
              }
            }
            if(tes==false){
                result.push_back((*it).v/2);
                numbersVertex++;
            }
          }
        }
      }

      cout << numbersVertex << endl;
      vector<int>::iterator itv;
      for(itv=result.begin(); itv!=result.end(); ++itv)
        cout << *(itv) << " ";
      cout << endl;
      return;
    }
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int z, n, m, u, v, x, y;
  cin >> z;
  for(int zz=0; zz<z; zz++)
  {
    cin >> n >> m >> u >> v;
    result.clear();
    for(int i=1; i<=2*n; i++)
    {
      visited[i] = false;
      G[i].clear();
    }
    for(int i=1; i<=n; i++)
    {
      node tmp = {1, 0, 2*i};
      G[2*i-1].push_back(tmp);
      node revtmp = {0, 0, 2*i-1};
      G[2*i].push_back(revtmp);
    }
    for(int i=0; i<m; i++)
    {
      cin >> x >> y;
      node tmp1 = {INFTY, 0, 2*y-1};
      G[2*x].push_back(tmp1);
      node revtmp1 = {0, 0, 2*y};
      G[2*x-1].push_back(revtmp1);

      node tmp2 = {INFTY, 0, 2*x-1};
      G[2*y].push_back(tmp2);
      node revtmp2 = {0, 0, 2*x};
      G[2*y-1].push_back(revtmp2);
    }
    EdKarp(m, n, 2*u, 2*v-1);
  }
  return 0;
}
