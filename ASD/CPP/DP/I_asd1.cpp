#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

void dfsUtil(int v, vector<int> *G, bool visited[], stack<int> &S, char *game)
{
   visited[v] = true;
   vector<int>::iterator it;
   vector<int>::iterator t;
   for(it=G[v].begin(); it!=G[v].end(); ++it)
   {
     if(!visited[*it])
       dfsUtil(*it, G, visited, S, game);
   }
   for(t=G[v].begin(); t!=G[v].end(); ++t)
   {
       if(game[*t]=='P')
        {
          game[v] = 'W';
          break;
        }
    }
   if(game[v]!='W')
      game[v] = 'P';
   S.push(v);
}

void DFS(int n, vector<int>* G, char *game)
{
   vector<int>::iterator it;
   stack<int> S;
   bool *visited = new bool[n];
   for(int i=0; i<n; i++)
      visited[i]=false;
   for(int i=0; i<n; i++)
      if(visited[i]==false)
        dfsUtil(i, G, visited, S, game);
   for(int i=0; i<n; i++)
      cout << game[i] << " ";
   delete [] visited;
}

int main()
{
   ios_base::sync_with_stdio(0);
   int z, n, m, v, w;
   cin >> z;
   for(int zz=0; zz<z; zz++)
   {
     cin >> n;
     vector<int>* G = new vector<int> [n];
     char *game = new char[n+1];
     game[n] = 0;
     for(int i=0; i<n; i++)
       game[i] = 0;
     for(int i=0; i<n; i++)
     {
       cin >> m;
       if(m==0)
          game[i] = 'P';
       for(int j=0; j<m; j++)
       {
         cin >> v;
         G[i].push_back(v);
       }
     }
     DFS(n, G, game);
     cout << endl;
     delete [] game;
     delete [] G;
   }
   return 0;
}
