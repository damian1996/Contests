#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000000
int KMP[N+1];
#define INFTY 10000000

void prefSuf(string data, int len)
{
    int i = -1;
    KMP[0] = -1;
    for(int j=1; j<len; j++)
    {
        while(i>=0 && data[j]!=data[i+1])
            i = KMP[i];
        i++;
        KMP[j] = i;
    }
}
int compute(int len)
{
    int n = len-1;
    int poz = n;
    while(poz>0)
    {
      if(n%(n-KMP[poz])==0)
      {
        return (n-KMP[poz]);
      }
      else
      {
        poz = KMP[poz];
      }
    }
    return 0;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    int z;
    string in, data;
    cin >> z;
    for(int zz=0; zz<z; zz++)
    {
        cin >> in;
        data = "#" + in;
        int len = data.size();
        prefSuf(data, len);
        int result = compute(len);
        cout << (len-1)/result << "\n";
    }
    return 0;
}
