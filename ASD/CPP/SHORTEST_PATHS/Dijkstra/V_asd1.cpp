#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <utility>
using namespace std;
#define N 50000
#define M 200000

vector< pair<int, int> > G[N+1];
long long result[N+1];
int poprzednik[N+1];
priority_queue< pair<int, int>, vector< pair<int, int> > , greater< pair <int, int> > > Q;

void relax(int u, int v, int waga)
{
  if(result[v] > result[u] + waga)
  {
    result[v] = result[u] + waga;
    poprzednik[v] = u;
    Q.push(make_pair(result[v], v));
  }
}

void dijkstra(int n)
{
      //for(int i=1; i<=n; i++)
    //Q.push(make_pair(result[i], i));
    Q.push(make_pair(result[1], 1));
    while(!Q.empty())
    {
      vector< pair<int, int> >::iterator it;
      pair <int,int> u = Q.top();
      Q.pop();
      for(it=G[u.second].begin(); it!=G[u.second].end(); ++it)
      {
        int x = (*it).second;
        int y = (*it).first;
        relax(u.second, y, x);
      }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int n, m, z, a, b, k;
    long long inf = 0;
    cin >> z;
    for(int zz=0; zz<z; zz++)
    {
        Q = priority_queue< pair<int, int>, vector< pair<int, int> > , greater< pair <int, int> > > ();
        cin >> n >> m;
        for(int i=1; i<=n; i++)
        {
          inf = 0;
          G[i].clear();
          result[i] = 0;
          poprzednik[i] = -1;
        }
        for(int i=0; i<m; i++)
        {
            cin >> a >> b >> k;
            inf += k;
            G[a].push_back(make_pair(b,k));
        }
        inf++;
        for(int i=2; i<=n; i++)
        {
          result[i] = inf;
        }
        result[1] = 0;
        dijkstra(n);
        if(result[n]!=inf)
          cout << result[n] << endl;
        else
          cout << "BRAK" << endl;
    }
    return 0;
}
