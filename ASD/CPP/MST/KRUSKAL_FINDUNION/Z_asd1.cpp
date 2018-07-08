#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define N 10000
#define M 1000000

struct input
{
  long long a, b, w;
  bool operator< (const input &c2) const
  {
    if(w < c2.w)
      return true;
    else
      return false;
  }
};

input arr[M+1];
long long up[N+1];
long long heightSubtree[N+1];
vector<input> E;

long long find(int x)
{
  if(up[x] != x)
  {
    up[x] = find(up[x]);
  }
  return up[x];
}

void unia(int s1, int s2)
{
  long long x = find(s1);
  long long y = find(s2);
  if(heightSubtree[x]>heightSubtree[y])
    up[y] = x;
  else
    up[x] = y;

  if(heightSubtree[x]==heightSubtree[y])
    heightSubtree[y]++;
}

long long Kruskal(int n, int m)
{
  long long result = 0;
  vector<input>::iterator it;
  sort(E.begin(), E.end());
  for(int i=1; i<=n; i++)
  {
    up[i] = i;
    heightSubtree[i] = 0;
  }
  for(it = E.begin(); it!=E.end(); ++it)
  {
    long long s1 = find((*it).a);
    long long s2 = find((*it).b);
    if(s1!=s2)
    {
      result += (*it).w;
      unia(s1, s2);
    }
  }
  return result;
}

int main()
{
  long long z, n, m;
  cin >> z;
  for(int zz=0; zz<z; zz++)
  {
    cin >> n >> m;
    for(int i=1; i<=m; i++)
    {
      cin >> arr[i].a >> arr[i].b >> arr[i].w;
      E.push_back(arr[i]);
    }
    long long res = Kruskal(n, m);
    cout << res << endl;
    E.clear();
  }
  return 0;
}
