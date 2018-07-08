#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define N 400000
#define M 1048576
#define X 440564289
const int P = ((1<<27)*15+1);
vector<ll> first;
vector<ll> second;
vector<ll> splot;
ll pot[20] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576};
ll add(ll x, ll y)
{
  return (x+y)%P;
}
ll sub(ll x, ll y)
{
  return (x-y+P)%P;
}
ll mul(ll x, ll y)
{
  return (x*y)%P;
}
bool convertToVector(const string &a, int bsize, vector<ll> &arr, int p)
{
  bool res = false;
  int asize = a.size();
  for(int i=asize-1; i>0; i--)
    arr.push_back(a[i]-'0');
  if(a[0]=='-')
  {
    res = true;
    asize--;
  }
  else arr.push_back(a[0]-'0');
  if(asize<bsize)
  {
    for(int i=0; i<bsize-asize; i++)
      arr.push_back(0);
    asize = bsize;
  }
  for(int i=asize; i<p; i++)
    arr.push_back(0);
  return res;
}
ll fastPot(ll x, ll n)
{
  if(n==0)
    return 1;
  if(n%2==1)
  {
    ll tmp = fastPot(x, (n-1)/2);
    return mul(x, mul(tmp, tmp));
  }
  ll t = fastPot(x, n/2);
  return mul(t, t);
}
vector<ll> eval(int n, ll omega, const vector<ll>& arr)
{
  vector<ll> A0;
  vector<ll> A1;
  vector<ll> ret;
  if(n==1)
    return arr;
  for(int i=0; i<n; i++)
    ret.push_back(0);
  for(int k=0; k<n; k++)
  {
    if(k%2==1) A1.push_back(arr[k]);
    else A0.push_back(arr[k]);
  }
  A0 = eval(n/2, mul(omega, omega), A0);
  A1 = eval(n/2, mul(omega, omega), A1);
  ll wk = 1;
  for(int k=0; k<n/2; k++)
  {
    if(k>0)
      wk = mul(wk, omega);
    else if(k==0)
      wk = 1;
    ret[k]=add(A0[k],mul(wk, A1[k]));
    ret[add(n/2,k)]=sub(A0[k], mul(wk, A1[k]));
  }
  return ret;
}
void FFT(const string &a, const string &b)
{
  if(a=="0" || b=="0")
  {
    cout << 0 << endl;
    return;
  }
  int bsize = b.size(), asize=a.size(), sizePoly=0, siz=0;
  if(b[0]=='-') bsize--;
  if(a[0]=='-') asize--;
  bool minusA = false, minusB = false;
  siz = 2*max(asize, bsize);
  for(int i=0; i<20; i++)
  {
    if(pot[i]>=siz)
    {
      sizePoly = pot[i];
      break;
    }
  }
  vector<ll> evalA;
  vector<ll> evalB;
  minusA = convertToVector(a, bsize, first, sizePoly);
  minusB = convertToVector(b, asize, second, sizePoly);

  ll omega = fastPot(X, (1<<27)/sizePoly);
  evalA = eval(sizePoly, omega, first);
  evalB = eval(sizePoly, omega, second);
  for(int i=0; i<sizePoly; i++)
      splot.push_back(evalA[i]*evalB[i]);
  ll wspr = fastPot(omega, P-2);
  splot = eval(sizePoly, wspr, splot);
  for(int i=0; i<sizePoly; i++)
    splot[i] = mul(splot[i],fastPot(sizePoly,P-2));
  for(int i=0; i<sizePoly-1; i++)
  {
      splot[i+1] += splot[i]/10;
      splot[i] = splot[i]%10;
  }
  splot[sizePoly-1] = splot[sizePoly-1]%10;

  if((minusA && !minusB) || (!minusA && minusB))
    cout << "-";
  ll cnt=0;
  for(int i=sizePoly-1; i>=0; i--)
  {
    if(splot[i]==0) cnt++;
    else break;
  }
  for(int i=sizePoly-1-cnt; i>=0; i--)
    cout << splot[i];
  cout << endl;
}
int main()
{
  std::ios_base::sync_with_stdio(false);
  ll z;
  string a, b;
  cin >> z;
  while(z--)
  {
    first.clear();
    second.clear();
    splot.clear();
    cin >> a >> b;
    FFT(a, b);
  }
  return 0;
}
