#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <utility>
using namespace std;
#define N 50000
#define M 1000000

struct data
{
  int v, w, t, a, l;
};

vector<data > G[N+1];
long long result[N+1];
priority_queue< pair<int, int>, vector< pair<int, int> > , greater< pair <int, int> > > Q;

void relax(int u, int v, int waga, int t, int a, int l)
{
  long long tmp = result[u]%t;
  if((a==0 && t==0 && l==0) || (((result[u] - a)%t + t)%t < l))
  {
    if(result[v] > result[u] + waga)
    {
      result[v] = result[u] + waga;
      Q.push(make_pair(result[v], v));
    }
  }
  else
  {
    tmp = t - ((result[u] - a)%t+ t)%t;
    if(result[v] > result[u] + waga + tmp)
    {
      result[v] = result[u] + waga + tmp;
      Q.push(make_pair(result[v], v));
    }
  }
}

void dijkstra(int n)
{
    Q.push(make_pair(result[1], 1));
    while(!Q.empty())
    {
      vector< data >::iterator it;
      pair <int,int> u = Q.top();
      Q.pop();
      for(it=G[u.second].begin(); it!=G[u.second].end(); ++it)
      {
        int v1 = (*it).v;
        int w1 = (*it).w;
        int t1 = (*it).t;
        int a1 = (*it).a;
        int l1 = (*it).l;
        relax(u.second, v1, w1, t1, a1, l1);
      }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int n, m, z, u, a, l, t, v, w;
    long long inf = 0;
    cin >> z;
    for(int zz=0; zz<z; zz++)
    {
        Q = priority_queue< pair<int, int>, vector< pair<int, int> > , greater< pair <int, int> > > ();
        cin >> n >> m;
        inf = 0;
        for(int i=0; i<=n; i++)
        {
          G[i].clear();
          result[i] = 0;
        }
        for(int i=0; i<m; i++)
        {
            cin >> u >> v >> w >> t >> a >> l;
            data temp = {v, w, t, a, l};
            G[u].push_back(temp);
            inf+=(w + t);
        }
        for(int i=2; i<=n; i++)
        {
          result[i] = inf;
        }
        result[1] = 0;
        dijkstra(n);
        if(result[n]!=inf)
          cout << result[n] << endl;
        else
          cout << "NIE" << endl;
    }
    return 0;
}
