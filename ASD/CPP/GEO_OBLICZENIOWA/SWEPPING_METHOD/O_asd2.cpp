#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
using namespace std;
#define N 150000
const char start = '0';
const char en = '1';
#define ll long long
struct circle
{
  ll x, y, rad;
};
vector<circle> circs;
struct event
{
  char type;
  int nr;
};
bool eventSort(const event &c1, const event &c2)
{
  ll c1x, c2x, c1y=circs[c1.nr-1].y, c2y=circs[c2.nr-1].y;
  if(c1.type==start)
    c1x = circs[c1.nr-1].x - circs[c1.nr-1].rad;
  else
    c1x = circs[c1.nr-1].x + circs[c1.nr-1].rad;
  if(c2.type==start)
    c2x = circs[c2.nr-1].x - circs[c2.nr-1].rad;
  else
    c2x = circs[c2.nr-1].x + circs[c2.nr-1].rad;

  if(c1x<c2x)
    return true;
  else if(c1x==c2x)
  {
    if(c1y<c2y)
      return true;
    else if(c1y==c2y)
    {
      if(c1.type==en && c2.type==start)
        return true;
      else
        return false;
    }
    else
      return false;
  }
  else
    return false;
}
vector<event> poset;
ll dist(ll ax, ll ay, ll bx, ll by)
{
  return (bx-ax)*(bx-ax)+(by-ay)*(by-ay);
}
struct compare {
    bool operator()(const pair<int, char>& a, const pair<int, char>& b) {
        ll ax = circs[a.first-1].x, ay = circs[a.first-1].y, arad = circs[a.first-1].rad;
        ll bx = circs[b.first-1].x, by = circs[b.first-1].y, brad = circs[b.first-1].rad;
        if(a.first==b.first)
        {
          if(a.second==b.second)
            return false;
          else
            return a.second==start;
        }
        if(dist(ax, ay, bx, by)<((arad-brad)*(arad-brad)))
        {
            if(a.second==en && b.second==start)
              return false;
            else if (a.second==start && b.second==en)
              return true;
            else if(a.second==start && b.second==start)
              return (ay+arad<by+brad)?false:true;
            else
              return (ay+arad<by+brad)?true:false;
        }
        else
        {
          if(ay+arad==by+brad)
          {
            if(ax<bx) return true;
            else return false;
          }
          else
            return (ay+arad<by+brad)?false:true;

        }
    }
};
set<pair<int, char>, compare> htSort;
int result[N+1];

void heightSort(int n)
{
  for(ll i=0; i<2*n; i++)
  {
    if(poset[i].type==start)
    {
      pair<int, char> pS(poset[i].nr, start);
      pair<int, char> pE(poset[i].nr, en);
      htSort.insert(pS);
      htSort.insert(pE);
      auto it = htSort.find(pS);
      pair<int, char> fr = *it;
      if(it==htSort.begin())
      {
          result[fr.first] = 0;
      }
      else
      {
        pair<int, char> sc = *(--it);
        if(sc.second != fr.second)
          result[fr.first] = result[sc.first];
        else
        {
          if(fr.first==sc.first)
            result[fr.first] = result[sc.first];
          else
            result[fr.first] = sc.first;
        }
      }
    }
    else
    {
      pair<int, char> pS(poset[i].nr, start);
      pair<int, char> pE(poset[i].nr, en);
      auto it = htSort.find(pS);
      htSort.erase(it);
      auto ite = htSort.find(pE);
      htSort.erase(ite);
    }
  }
}
int main()
{
  ll x, y, rad;
  int zz, n;
  cin >> zz;
  while(zz--)
  {
    cin >> n;
    for(int i=0; i<=n; i++)
      result[i] = 0;
    for(int i=1; i<=n; i++)
    {
      cin >> x >> y >> rad;
      circs.push_back({x, y, rad});
      poset.push_back({start, i});
      poset.push_back({en, i});
    }
    sort(poset.begin(), poset.end(), eventSort);
    heightSort(n);
    for(int i=1; i<=n; i++)
      cout << result[i] << endl;
    circs.clear();
    poset.clear();
    htSort.clear();
  }
  return 0;
}
