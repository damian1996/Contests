#include <iostream>
#include <vector>
using namespace std;
#define M 500000
#define N 50000
vector<int> G[N+2];
vector<int> GT[N+2];
int whichScc[N+1];
int postorder[N+1];
bool visited[N+1];
int nr = 1;
int countScc = 0;

void DFS(int v)
{
  visited[v] = true;
  vector<int>::iterator it;
  for(it=G[v].begin(); it != G[v].end(); ++it)
  {
    if(!visited[*it])
      DFS(*it);
  }
  postorder[nr] = v;
  nr++;
}
void DFST(int v)
{
  whichScc[v] = countScc;
  visited[v] = true;
  vector<int>::iterator it;
  for(it=GT[v].begin(); it != GT[v].end(); ++it)
  {
    if(!visited[*it])
      DFST(*it);
  }
}
void scc(int n)
{
  for(int i=1; i<=n; i++)
  {
    if(!visited[i])
    {
      DFS(i);
    }
  }
  for(int i=1; i<=n; i++)
    visited[i] = false;

  for(int i=n; i>=1; i--)
  {
    if(!visited[postorder[i]])
    {
      countScc++;
      DFST(postorder[i]);
    }
  }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int z, n, m, a, b, k, x, y;
    cin >> z;
    for(int zz=0; zz<z; zz++)
    {
        cin >> n >> m;
        for(int i=0; i<m; i++)
        {
          cin >> a >> b;
          G[a].push_back(b);
          GT[b].push_back(a);
        }
        scc(n);
        cin >> k;
        for(int i=0; i<k; i++)
        {
          cin >> x >> y;
          if(whichScc[x]==whichScc[y])
            cout << "TAK" << endl;
          else
            cout << "NIE" << endl;
        }
        for(int i=1; i<=n; i++)
        {
          visited[i] = false;
          G[i].clear();
          GT[i].clear();
        }
        nr = 1;
        countScc = 0;
    }
    return 0;
}
