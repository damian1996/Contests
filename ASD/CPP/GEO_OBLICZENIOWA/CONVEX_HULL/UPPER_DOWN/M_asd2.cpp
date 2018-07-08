#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
#define N 300000
#define ll long long
struct P
{
  ll x, y;
};
bool vecSort(const P &c1, const P &c2)
{
  if(c1.x < c2.x)
    return true;
  else if(c1.x == c2.x)
  {
    if(c1.y < c2.y)
      return true;
    else
      return false;
  }
  else
    return false;
}
vector<P> points;
vector<P> hull;
ll det(P a, P b, P c)
{
  return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
ll areaHull()
{
  ll area = 0, size = hull.size();
  P mid;
  mid.x=0, mid.y=0;
  for(int i=1; i<size; i++)
    area+=det(mid, hull[i-1], hull[i]);
  area+=det(mid, hull[size-1], hull[0]);
  return area<0?-area:area;
}
void upperDown(int n)
{
  vector<P> s1;
  vector<P> s2;
  sort(points.begin(), points.end(), vecSort);
  s1.push_back(points[0]);
  s1.push_back(points[1]);
  for(int i=2; i<n; i++)
  {
    ll size = s1.size();
    while(size>1 && det(s1[size-2], s1[size-1], points[i])>=0)
    {
      s1.pop_back();
      size--;
    }
    s1.push_back(points[i]);
  }
  s2.push_back(points[n-1]);
  s2.push_back(points[n-2]);
  for(int i=n-3; i>=0; i--)
  {
    ll size = s2.size();
    while(size>1 && det(s2[size-2], s2[size-1], points[i])>=0)
    {
      s2.pop_back();
      size--;
    }
    s2.push_back(points[i]);
  }
  for(int i=0; i<s1.size()-1; i++)
    hull.push_back(s1[i]);
  for(int i=0; i<s2.size()-1; i++)
    hull.push_back(s2[i]);
  cout << areaHull() << endl;
}
int main()
{
  int z, n, x, y;
  cin >> z;
  while(z--)
  {
    hull.clear();
    points.clear();
    cin >> n;
    for(int i=0; i<n; i++)
    {
      cin >> x >> y;
      points.push_back({x, y});
    }
    upperDown(n);
  }
  return 0;
}
