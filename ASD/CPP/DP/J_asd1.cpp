#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 200001;
int weight[N];
int parent[N];
int result[N];
long long without[N];
long long withroot[N];
void minCoverUtil(int s, vector<int> *G, bool *visited)
{
  visited[s] = true;
  vector<int>::iterator it;
  for (it= G[s].begin(); it != G[s].end(); ++it)
  {
      if(!visited[*it] && *it != parent[s])
      {
              parent[*it] = s;
        minCoverUtil(*it, G, visited);
      }
  }
  long long suma1 = 0, suma2 = 0;
  for(it=G[s].begin(); it != G[s].end(); ++it)
  {
    if(*it!=parent[s])
    {
      suma1 += min(without[*it], withroot[*it]);
      suma2 += withroot[*it];
    }
  }
  withroot[s] = (weight[s] + suma1);
  without[s] = min(withroot[s], suma2);
  if(withroot[s]<=suma2)
    result[s] = 1;
  else
      result[s] = 0;
}
void minCover(int n, vector<int> *G)
{
  bool visited[n];
  for (int i=1; i<=n; i++)
      visited[i] = false;
  for (int u=1; u<=n; u++)
  {
     if (visited[u] == false)
       minCoverUtil(u, G, visited);
  }
  cout << min(withroot[1], without[1]) << endl;
}
void rekur(int s, vector<int> *G)
{
  if(parent[s]!= -1 && result[parent[s]]==0)
     result[s] = 1;
  else if(parent[s]!=-1 && result[parent[s]]==1)
  {
    if(withroot[s]<=without[s]) result[s] = 1;
    else result[s] = 0;
  }
  vector<int>::iterator it;
  for(it=G[s].begin(); it != G[s].end(); ++it)
  {
    if(*it != parent[s])
      rekur(*it, G);
  }
}
int main()
{
   ios_base::sync_with_stdio(0);
   int n, z, x, v;
   vector<int> *G;
   cin >> z;
   for(int zz=0; zz<z; zz++)
   {
      cin >> n;
      G = new vector<int> [n+1];
      for(int i=1; i<=n; i++)
        cin >> weight[i];
      for(int i=2; i<=n; i++)
      {
        cin >> x >> v;
        G[v].push_back(x);
        G[x].push_back(v);
      }
      for(int i=1; i<=n; i++)
      {
        without[i] = 0;
        withroot[i] = 0;
        parent[i] = -1;
        result[i] = 0;
      }
      minCover(n, G);
      rekur(1, G);
      for(int i=1; i<=n; i++)
        cout << result[i];
      cout << endl;
      delete [] G;
   }
   return 0;
}
