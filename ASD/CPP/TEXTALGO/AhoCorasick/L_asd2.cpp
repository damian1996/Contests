#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;
#define N (1<<20)
#define white '0'
#define gray '1'
#define black '2'
int mov[N+1][2];
int fail[N+1];
int orderBFS[N+1];
bool acptStates[N+1];
char col[N+1];

int add(int state, char letter, int &nrSts) // s[i] - '0';
{
  if(mov[state][letter - '0'] > -1){
    return mov[state][letter - '0'];
  }
  int r = nrSts;
  nrSts++;
  mov[state][letter - '0'] = r;
  for(int i=0; i<2; i++)
    mov[r][i] = -1;
  return r;
}
void addWord(string s, int &nrSts)
{
  int j = 0, len = s.size();
  for(int i=0; i<len; i++){
    j = add(j, s[i], nrSts);
  }
  acptStates[j] = true;
}
void BFS(int &nrSts)
{
  bool visited[nrSts];
  for(int i=0; i<nrSts; i++)
      visited[i] = false;
  int ord = 0;
  queue<int> Q;
  Q.push(0);
  visited[0] = true;
  orderBFS[0] = 0;
  while(!Q.empty())
  {
     int el = Q.front();
     Q.pop();
     for(int k=0; k<2; k++)
     {
       int t = mov[el][k];
       if(t!=-1 && !visited[t])
       {
         visited[t] = true;
         Q.push(t);
         orderBFS[++ord] = t;
       }
     }
   }
}
void utilWalk(int v, bool &cycle)
{
    col[v] = gray;
    for(int k=0; k<2; k++)
    {
        int t = mov[v][k];
        if(col[t]==white)
        {
          if(!acptStates[t] && !acptStates[fail[t]])
              utilWalk(t, cycle);
        }
        else
        {
            if(col[t]==gray)
                cycle = true;
        }
    }
    col[v] = black;
}
bool walk(int &nrSts)
{
  bool cycle = false;
  for(int i=0; i<nrSts; i++)
    col[i] = white;

  utilWalk(0, cycle);
  if(cycle) return true;
  else return false;
}
bool ahoCorasick(int n, int &nrSts)
{
  BFS(nrSts);
  fail[0] = 0;
  for(int i=0; i<2; i++)
    if(mov[0][i]!=-1)
      fail[mov[0][i]] = 0;
  for(int i=0; i<2; i++)
    if(mov[0][i]==-1)
      mov[0][i] = 0;
  for(int i=1; i<nrSts; i++)
  {
    int q = orderBFS[i];
    for(int j=0; j<2; j++)
    {
      int tmp = mov[q][j];
      if(tmp==-1)
        mov[q][j] = mov[fail[q]][j];
      else
        fail[tmp] = mov[fail[q]][j];
      if(acptStates[fail[tmp]]==true)
         acptStates[tmp] = true;
    }
  }
  bool x =  walk(nrSts);
  for(int i=0; i<nrSts; i++)
  {
    acptStates[i] = false;
    fail[i] = 0;
  }
  return x;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int z, n;
  string data;
  cin >> z;
  while(z--)
  {
    cin >> n;
    int nrSts = 1;
    for(int i=0; i<2; i++)
      mov[0][i] = -1;
    for(int i=0; i<n; i++)
    {
      cin >> data;
      addWord(data, nrSts);
    }
    if(ahoCorasick(n, nrSts)) cout << "TAK" << endl;
    else cout << "NIE" << endl;
  }
  return 0;
}
