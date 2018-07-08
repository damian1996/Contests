#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define N 100000
#define M 1000000
#define ll long long
#define INFTY 100000000002

struct node{
    int u;
    int v;
    ll flow;
    ll cap;
    int idx;
};

vector<node> G[N+1];
ll overflow[N+1];
ll height[N+1];
queue<int> active;
bool isActive[N+1];
int gapArr[N+1];
int ptr[N+1];

void Push(node& e, int d, ll n)
{
  height[e.v == d ? e.u : e.v];
    ll tmp = min(overflow[e.u == d ? e.u : e.v], e.cap - e.flow);
    if(d==e.u)
    {
        e.flow += tmp;
        G[e.v][e.idx].flow -= tmp;
        overflow[e.v] += tmp;
        overflow[e.u] -= tmp;
        if(!isActive[e.v] && overflow[e.v]>0)
        {
          isActive[e.v] = true;
          active.push(e.v);
        }
    }
    else
    {
        e.flow += tmp;
        G[e.u][e.idx].flow -= tmp;
        overflow[e.u] += tmp;
        overflow[e.v] -= tmp;
        if(!isActive[e.u] && overflow[e.u]>0)
        {
          isActive[e.u] = true;
          active.push(e.u);
        }
    }
}

void Relabel (int v, ll n, int s, int t)
{
    if(v==s || v==t)
      return;
    gapArr[height[v]]--;
    height[v] = 2*n + 2;
    for(node& e : G[v]){
      if(e.cap - e.flow > 0)
        height[v] = min(height[v], height[e.v == v ? e.u : e.v] + 1);
    }
    ptr[v] = 0;
    //height[v]++;
    gapArr[height[v]]++;
}

void gap(int k, ll n, int s, int t)
{
  for(int i=1; i<=n; i++){
    if(height[i]>=k && i!=s && i!=t){
      //cout << "dla " << i << " " << height[i] << " ";
      height[i] = max(height[i], n) + 1;
      //cout << height[i] << endl;
      ptr[i] = 0; // czy jesli nie zmieniam, to tez?
    }
  }
}

long long pushRelabel(ll n, ll m, int s, int t)
{
    height[s] = n;
    for(node& e : G[s])
    {
        if(e.u==s)
        {
            e.flow = e.cap;
            overflow[e.v] = e.flow;
            G[e.v][e.idx].flow = -e.flow;
            if(!isActive[e.v] && overflow[e.v]>0)
            {
              isActive[e.v] = true;
              active.push(e.v);
            }
        }
    }
    while(!active.empty())
    {
        int d = active.front();
        active.pop();
        isActive[d] = false;
        if(d == s || d == t) continue;
        int len = G[d].size();
        while(ptr[d]<len)
        {
          int e = ptr[d];
          if(G[d][e].cap-G[d][e].flow>0 && height[d] == height[G[d][e].v == d ? G[d][e].u : G[d][e].v] + 1)
          {
            Push(G[d][e], d, n);
            if(overflow[d]==0)
              break;
          }
          ptr[d]++;
        }
        if(overflow[d]>0) // &&  height[d]<2*(n+1))
        {
            if(gapArr[height[d]]==1 && height[d]<n)
                gap(height[d], n, s, t);
            else
              Relabel(d, n, s, t);
            if(!isActive[d])
            {
                isActive[d] = true;
                active.push(d);
            }
        }
    }
    return overflow[t];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int z, s, t, a, b;
    ll n, m, c;
    cin >> z;
    for(int zz=0; zz<z; zz++)
    {
        cin >> n >> m >> s >> t;
        for(int i=0; i<=n; i++)
        {
            gapArr[i] = 0;
            isActive[i] = false;
            height[i] = 0;
            overflow[i] = 0;
            ptr[i] = 0;
            G[i].clear();
        }
        for(int i=0; i<m; i++)
        {
            cin >> a >> b >> c;
            bool test = false;
            for(node& e : G[a])
            {
              if(e.u==a && e.v==b){
                e.cap += c;
                test = true;
                break;
              }
            }
            if(!test)
            {
              G[a].push_back({a, b, 0, c, G[b].size()});
              G[b].push_back({a, b, 0, 0, G[a].size()-1});
            }
        }

        long long result = pushRelabel(n, m, s, t);
        cout << result << '\n';
    }
    return 0;
}
