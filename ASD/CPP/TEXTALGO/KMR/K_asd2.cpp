#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
using namespace std;
#define N 500000
#define INFTY 10000000
int LCP[N+1];
int suf[N+1];
int wynik[N+1];
struct triple {
    int p1;
    int p2;
    int idx;
};
int KMR[25][N+1];
vector<triple> vecKmr;

bool kmrSort(const triple &c1, const triple &c2)
{
  if(c1.p1 < c2.p1)
    return true;
  else if(c1.p1==c2.p1)
  {
    if(c1.p2 < c2.p2)
      return true;
    else
      return false;
  }
  else
    return false;
}

void tmpKMR(int n, int i, int l)
{
    vecKmr.clear();
    if(i>n) {
        i = i/2;
        for(int j=0; j<n; j++)
        {
            if(j+n-i > n-1) {
              triple next = {KMR[l-1][j], -1, j};
              vecKmr.push_back(next);
            } else {
              triple next = {KMR[l-1][j], KMR[l-1][j+n-i], j};
              vecKmr.push_back(next);
            }
        }
    }
    else {
         for(int j=0; j<n; j++)
         {
            if(j+i > n-1) {
              triple next = {KMR[l-1][j], -1, j};
              vecKmr.push_back(next);
            } else {
              triple next = {KMR[l-1][j], KMR[l-1][j+i], j};
              vecKmr.push_back(next);
            }
         }
    }

    sort(vecKmr.begin(), vecKmr.end(), kmrSort);
    int curr1 = -1, curr2 = -1, counter = -1;
    for(int j=0; j<vecKmr.size(); ++j){
        if(curr1==vecKmr[j].p1 && curr2==vecKmr[j].p2){
            KMR[l][vecKmr[j].idx] = counter;
        } else {
            curr1 = vecKmr[j].p1;
            curr2 = vecKmr[j].p2;
            KMR[l][vecKmr[j].idx] = ++counter;
        }
    }
}

int computeKMR(string data, int n)
{
    vecKmr.clear();
    for(int i=0; i<n; i++)
        KMR[0][i] = data[i] - 'A';

    int i=1, l=1;
    for(i=1, l=1; i<n; i*=2, l++)
    {
        tmpKMR(n, i, l);
    }
    if(i>n){
      tmpKMR(n, i, l);
      return l;
    }
    return l-1;
}

int arrSuffixes(string data, int n)
{
    int index = computeKMR(data, n);
    for(int i=0, j=n-1; i<n; i++, j--)
        suf[KMR[index][i]] = i;
    return index;
}

void computeLCP(string data, int n)
{
    for(int i=0; i<n-1; i++)
    {
        int l = 0, h = min(n-suf[i], n-suf[i+1]);
        while(l<=h)
        {
            int m = l + (h-l)/2, p = 1, r = 0;
            while(p*2<m)
            {
                p *= 2;
                r++;
            }
            if(m==0 || m==1 || p*2==m)
            {
                if(KMR[r][suf[i]]==KMR[r][suf[i+1]] && KMR[r][suf[i]+m/2]==KMR[r][suf[i+1]+m/2])
                {
                    LCP[i]=m;
                    l = m+1;
                }
                else
                {
                    h = m-1;
                }
            }
            else
            {
                if(KMR[r][suf[i]]==KMR[r][suf[i+1]] && KMR[r][suf[i]+m-p]==KMR[r][suf[i+1]+m-p])
                {
                    LCP[i]=m;
                    l = m+1;
                }
                else
                {
                    h = m-1;
                }
            }
        }
    }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int z, n, len, index;
  string data;
  cin >> z;
  for(int zz=0; zz<z; zz++)
  {
      cin >> n;
      cin >> data;
      for(int i=0; i<n; i++)
        LCP[i] = 0;

      index = arrSuffixes(data, n);
      computeLCP(data, n);
      wynik[suf[0]] = LCP[0];
      for(int i=1; i<n-1; i++)
          wynik[suf[i]] = max(LCP[i], LCP[i-1]);
      wynik[suf[n-1]] = LCP[n-2];
      for(int i=0; i<n; i++)
          cout << wynik[i] << " ";
      cout << endl;
  }
  return 0;
}
