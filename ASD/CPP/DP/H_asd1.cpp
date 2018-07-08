#include <iostream>
#include <stack>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

void dfsUtil(int v, vector<int> *G, bool visited[], stack<int> &S)
{
   visited[v] = true;
   vector<int>::iterator it;
   for(it=G[v].begin(); it!=G[v].end(); ++it)
   {
     if(!visited[*it])
       dfsUtil(*it, G, visited, S);
   }
   S.push(v);
}

void DFS(int n, vector<int>* G, int *toposort)
{
   vector<int>::iterator it;
   stack<int> S;
   bool *visited = new bool[n];
   for(int i=1; i<=n; i++)
      visited[i]=0;
   for(int i=1; i<=n; i++)
      if(visited[i]==false)
        dfsUtil(i, G, visited, S);
   for(int i=1; i<=n ; i++)
   {
       int x = S.top();
     toposort[i]=x;
     S.pop();
   }
   delete [] visited;
}

void longestPath(int n, vector<int>* G, int *toposort, int *lenPath, int *lenPath2)
{
  for(int i=1; i<n+1; i++)
  {
     lenPath[i] = 1;
     lenPath2[i] = 0;
  }
  for(int i=1; i<n+1; i++)
  {
      int tmp = toposort[i];
      vector<int>::iterator it;
      if(lenPath[tmp]!=n+1)
      {
        for(it = G[tmp].begin(); it!=G[tmp].end(); ++it)
        {
          if(lenPath[*it] < lenPath[tmp] + 1)
             lenPath[*it] = lenPath[tmp] + 1;
        }
      }
  }
  vector<int>* rev = new vector<int> [n+1];
  for(int i=1; i<n+1; i++)
  {
          vector<int>::iterator it;
          for(it = G[i].begin(); it!=G[i].end(); ++it)
                      rev[*it].push_back(i);
  }
  DFS(n, rev, toposort);

  for(int i=1; i<n+1; i++)
  {
      int tmp = toposort[i];
      vector<int>::iterator it;
      if(lenPath2[tmp]!=n+1)
      {
        for(it = rev[tmp].begin(); it!=rev[tmp].end(); ++it)
        {
          if(lenPath2[*it] < lenPath2[tmp] + 1)
             lenPath2[*it] = lenPath2[tmp] + 1;
        }
      }
  }
  for(int i=1; i<n+1; i++)
     cout << lenPath[i]+lenPath2[i]<< " ";
  cout << endl;
  delete [] rev;
}
int main()
{
   ios_base::sync_with_stdio(0);
   int z, n, m, v, w;
   cin >> z;
   for(int zz=0; zz<z; zz++)
   {
     cin >> n >> m;
     vector<int>* G = new vector<int> [n+1];
     int *lenPath = new int[n+1];
     int *lenPath2 = new int[n+1];
     int *toposort = new int[n+1];
     for(int i=0; i<m; i++)
     {
       cin >> v >> w;
       G[v].push_back(w);
     }
     DFS(n, G, toposort);
     longestPath(n, G, toposort, lenPath, lenPath2);
     delete [] toposort;
     delete [] G;
     delete [] lenPath;
     delete [] lenPath2;
   }
   return 0;
}
