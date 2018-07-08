#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define ll __int128
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
bool testKarpRabin(ll num)
{
  srand(time(NULL));
  if(num==2 || num==3) return true;
  if(num%2==0) return false;
  ll t = num-1, pot=1, s=0;
  while(1)
  {
    if(t%(pot*2)==0)
    {
      pot *= 2;
      s++;
    } else break;
  }
  ll d = (num-1)/pot;
  for(int k=0; k<1000; k++)
  {
    bool swiadek = false;
    ll a = 2 + rand() % (num - 3);
    ll res = fastPot(a, d, num);
    if(res==1 || res==num-1)
      continue;
    for(ll r=0; r<s; r++)
    {
      res = fastPot(res, 2, num);
      if(res==1) return false;
      if(res==num-1) {
        swiadek = true;
        break;
      }
    }
    if(swiadek==true) continue;
    return false;
  }
  return true;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    int z;
    long long n;
    cin >> z;
    while(z--)
    {
        cin >> n;
        ll nn = n;
        if(testKarpRabin(nn)) cout << "TAK" << endl;
        else cout << "NIE" << endl;
    }
}
