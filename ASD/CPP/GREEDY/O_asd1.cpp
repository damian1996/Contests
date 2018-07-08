#include <iostream>
#include <stack>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1000000;
vector<int> G[N+1];
bool special[N+1];
int numbOfPath[N+1];
int countFree[N+1];

void DFSutil(int v, bool *visited)
{
    visited[v] = true;
    vector<int>::iterator it;
    for(it=G[v].begin(); it != G[v].end(); ++it)
      if(!visited[*it])
      {
        DFSutil(*it, visited);
      }
    int sumFree = 0;
    int sumAll = 0;
    int sumCountFree = 0;
    for(it=G[v].begin(); it != G[v].end(); ++it)
    {
      if(countFree[*it]>0)
      {
        sumFree++;
        sumCountFree += countFree[*it];
      }
      sumAll += numbOfPath[*it];
    }
    if(sumFree>1)
    {
      numbOfPath[v] = sumAll + 1;
      special[v] = false;
    }
    else if(sumFree==1)
    {
      if(special[v])
      {
        numbOfPath[v] = sumAll + 1;
        special[v] = false;
      }
      else
      {
        numbOfPath[v] = sumAll;
        countFree[v] = 1;
      }
    }
    else
    {
      if(special[v])
        countFree[v] = 1;
      numbOfPath[v] = sumAll;
    }
}

int DFS(int n)
{
  bool visited[n+1];
  for(int i=0; i<=n; i++)
    visited[i] = false;
  for(int i=1; i<=n; i++)
  {
    if(!visited[i])
      DFSutil(i, visited);
  }
}

int main()
{
   ios_base::sync_with_stdio(0);
   int z, n, m, v, w, spec;
   cin >> z;
   for(int zz=0; zz<z; zz++)
   {
     cin >> n;
     for(int i=0; i<=n; i++)
     {
       numbOfPath[i] = 0;
       special[i] = false;
       countFree[i] = 0;
       G[i].clear();
     }
     for(int i=1; i<n; i++)
     {
        cin >> v >> w;
        G[v].push_back(w);
        G[w].push_back(v);
     }
     cin >> m;
     for(int i=0; i<m; i++)
     {
       cin >> spec;
       special[spec]=true;
     }
     DFS(n);
     cout << numbOfPath[1] << endl;
   }
   return 0;
}
