#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define INFTY 10000000000
vector<pair<ll, ll>> s;
vector<pair<ll, ll>> f;
ll mul(ll x, ll y, ll num)
{
  return (x*y)%num;
}
ll fastPot(ll x, ll n, ll num)
{
  if(n==0)
    return 1;
  if(n%2==1)
  {
    ll tmp = fastPot(x, (n-1)/2, num);
    return mul(x, mul(tmp, tmp, num), num);
  }
  ll t = fastPot(x, n/2, num);
  return mul(t, t, num);
}
ll computeLogDisc(ll a, ll b, ll p)
{
  ll m = sqrt(p) + 1, value = 1, currVal = 1;
  ll revb = fastPot(b, p-2, p), cv = fastPot(fastPot(a, m, p), p-2, p), pot = fastPot(a, m, p);

  for(ll i=0; i<m; i++)
  {
    if(i>0) currVal = mul(currVal, a, p);
    ll val = mul(currVal, revb, p);
    s.push_back(make_pair(val, i));
  }
  //for(int i=0; i<s.size(); i++)
    //cout << s[i].first << "  " << s[i].second << endl;
  //cout << endl;
  sort(s.begin(), s.end());

  currVal = 1;
  for(ll i=0; i<m; i++)
  {
    f.push_back(make_pair(currVal, i));
    currVal = mul(currVal, cv, p);
    //currVal = mul(currVal, pot, p);
  }
  //for(int i=0; i<f.size(); i++)
    //cout << f[i].first << "  " << f[i].second << endl;
  //cout << endl;
  sort(f.begin(), f.end());

  ll minRes = INFTY;
  for(ll i=0, j=0; i<m && j<m; )
  {
    if(s[i].first==f[j].first)
    {
        ll y = f[j].second*m+s[i].second;
        if(y<minRes) minRes = y;
        j++;
    }
    else if(s[i].first>f[j].first) j++;
    else i++;
  }
  if(minRes!=INFTY) return minRes;
  else return -1;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    int z;
    ll a, b, p;
    cin >> z;
    while(z--)
    {
        s.clear();
        f.clear();
        cin >> a >> b >> p;
        cout << computeLogDisc(a, b, p) << endl;
    }
}
