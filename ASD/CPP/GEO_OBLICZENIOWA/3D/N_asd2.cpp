#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;
#define N 50
#define ll double
#define eps 1e-9
#define INFTY 1e10
struct P
{
  ll x, y, z;
};
vector<P> points;
P prodVec(P a, P b, P c)
{
  ll vecX = (b.y-a.y)*(c.z-a.z)-(b.z-a.z)*(c.y-a.y);
  ll vecY = (b.z-a.z)*(c.x-a.x)-(b.x-a.x)*(c.z-a.z);
  ll vecZ = (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
  P crProd = {vecX, vecY, vecZ};
  return crProd;
}
ll scalar(P a, P b, P c)
{
  return (b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y)+(b.z-a.z)*(c.z-a.z);
}
ll scalar2(P a, P b)
{
  return a.x*b.x + a.y*b.y + a.z*b.z;
}
P subtract(P vec1, P vec2)
{
  ll one = vec1.x - vec2.x;
  ll two = vec1.y - vec2.y;
  ll three = vec1.z - vec2.z;
  P ret = {one, two, three};
  return ret;
}
ll findNearest(P M, int n)
{
  ll minDist = INFTY;
  for(int i=0; i<n; i++)
  {
    for(int j=1; j<n; j++)
    {
      for(int k=2; k<n; k++)
      {
        P crProd = prodVec(points[i], points[j], points[k]);
        ll lenPerVec = sqrt(crProd.x*crProd.x+crProd.y*crProd.y+crProd.z*crProd.z);
        P normalVec = {crProd.x/lenPerVec, crProd.y/lenPerVec, crProd.z/lenPerVec};
        int pos = 0, neg = 0;
        for(int l=0; l<n; l++)
        {
          P vec1;
          if(points[i].x==points[l].x && points[i].y==points[l].y && points[i].z==points[l].z)
            vec1 = subtract(points[i], points[k]);
          else
            vec1 = subtract(points[k], points[l]);
          ll val = scalar2(vec1, crProd);
          if(val<=0) neg++;
          else if(val>=0) pos++;
        }
        if(pos==n || neg==n)
        {
          //zew
          P vec = subtract(M, points[j]);
          ll dist = scalar2(normalVec, vec);
          if(dist<minDist)
            minDist = dist;
        }
      }
    }
  }
  return minDist;
}
int main()
{
  int zz, n;
  double x, y, z;
  cin >> zz;
  while(zz--)
  {
    points.clear();
    cin >> x >> y >> z;
    P M = {x, y, z};
    cin >> n;
    for(int i=0; i<n; i++)
    {
      cin >> x >> y >> z;
      points.push_back({x, y, z});
    }
    cout << fixed << findNearest(M, n) << endl;
  }
  return 0;
}
