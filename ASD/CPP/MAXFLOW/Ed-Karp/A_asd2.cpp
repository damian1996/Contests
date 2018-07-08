#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define N 100
#define M 1000
#define INFTY 1000000002

long long capacity[N+1][N+1];
long long flow[N+1][N+1];
long long P[N+1];

bool BFS(long long n, long long s, long long t)
{
  long long m, t1, t2;
  queue<long long> Q;
  Q.push(s);
  while(!Q.empty())
  {
    long long el = Q.front();
    Q.pop();
    for(long long v=1; v<=n; v++)
    {
      if(capacity[el][v] - flow[el][v] > 0 && P[v]==-1)
      {
        P[v] = el;
        if(v!=t)
          Q.push(v);
        else
        {
          m = INFTY;
          t2 = v;
          while(true)
          {
            m = min(m, capacity[P[t2]][t2] - flow[P[t2]][t2]);
            if(P[t2]==s)
              break;
            t2 = P[t2];
            //t1 = P[t1];
          }
          while(true)
          {
            flow[P[v]][v] += m;
            flow[v][P[v]] = -flow[P[v]][v];
            if(P[v]==s)
              break;
            v = P[v];
          }
          return true;
        }
      }
    }
  }
  return false;
  /*if(P[t] == -1){
    return false;
  }
  else return true;*/
}

long long EdKarp(long long m, long long n, long long s, long long t)
{
  long long result = 0;
  while(true)
  {
    for(long long i=1; i<=n; i++)
      P[i] = -1;

    bool test = BFS(n, s, t);
    if(test)
      continue;
    else
    {
      for(long long i=1; i<=n; i++)
        result += flow[s][i];
      return result;
    }
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  long long z, n, m, s, t, a, b, c;
  cin >> z;
  for(long long zz=0; zz<z; zz++)
  {
    cin >> n >> m >> s >> t;
    for(long long i=1; i<=n; i++)
    {
      for(long long j=1; j<=n; j++)
      {
        capacity[i][j] = 0;
        flow[i][j] = 0;
      }
    }
    for(long long i=0; i<m; i++)
    {
      cin >> a >> b >> c;
      capacity[a][b] += c;
    }
    long long result = EdKarp(m, n, s, t);
    cout << result << endl;
  }
  return 0;
}
