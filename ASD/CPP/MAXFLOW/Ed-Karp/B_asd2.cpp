#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define N 100
#define M 100
#define INFTY 1000000005

long long capacity[M+N+2][M+N+2];
long long flow[M+N+2][M+N+2];
long long P[M+N+2];
//bool in[N+1][M+1];
//long long fabr[N+1];
//long long shops[M+1];

bool BFS(long long mm, long long n, long long s, long long t)
{
  long long m, t1, t2;
  queue<long long> Q;
  Q.push(s);
  while(!Q.empty())
  {
    long long el = Q.front();
    Q.pop();
    for(long long v=0; v<=mm+n+1; v++)
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
    for(long long i=0; i<=m+n+1; i++)
      P[i] = -1;

    bool test = BFS(m, n, s, t);
    if(test)
      continue;
    else
    {
      for(long long i=0; i<=m+n+1; i++)
        result += flow[s][i];
      return result;
    }
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  long long z, n, m, s, t, fabr, shop;
  bool in;
  cin >> z;
  for(long long zz=0; zz<z; zz++)
  {
    cin >> n >> m;
    for(long long i=0; i<n+m+2; i++)
    {
      for(long long j=0; j<n+m+2; j++)
      {
        capacity[i][j] = 0;
        flow[i][j] = 0;
      }
    }
    for(int i=1; i<=n; i++)
    {
      cin >> fabr;
      capacity[0][i] = fabr;
    }
    for(int i=1; i<=m; i++)
    {
      cin >> shop;
      capacity[n+i][m+n+1] = shop;
    }
    for(int i=1; i<=n; i++)
    {
      for(int j=1; j<=m; j++)
      {
        cin >> in;
        if(in==1)
          capacity[i][n+j] = INFTY;
      }
    }

    long long result = EdKarp(m, n, 0, m+n+1);
    cout << result << endl;
  }
  return 0;
}
