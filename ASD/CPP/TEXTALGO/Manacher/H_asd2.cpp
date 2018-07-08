#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000000
#define ll long long
#define INFTY 100000000002
char word[2*N+1];
int rad[2*N+1];

void manacher(int len)
{
    rad[0] = 0;
    int i = 1;
    int t = 0;
    while(i<len)
    {
        if(t<0) t=0;
        while(word[i-t-1]==word[i+t+1])
        {
            t++;
            if((i-t-1) < 0 || (i+t+1) >= len)
              break;
        }
        rad[i] = t+1;

        int k=1;
        while(k<=t && rad[i-k] != rad[i]-k)
        {
            rad[i+k] = min(rad[i-k], rad[i]-k);
            k++;
            if((i-k) < 0 || (i+k) >= len)
              break;
        }
        t -= k;
        i += k;
    }
}
bool checkAnswer(int a, int b, int len)
{
    if(rad[(2*(a+b))/2 - 1] >= (b-a+1))
      return true;
    else return false;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    int z, q, a, b, len;
    string in;
    cin >> z;
    for(int zz=0; zz<z; zz++)
    {
        cin >> in;
        len = in.size();
        for(int i=1; i<=len; i++)
        {
            word[2*i-1] = in[i-1];
            word[2*i] = '0';
        }
        manacher(2*len);
        cin >> q;
        for(int i=0; i<q; i++)
        {
            cin >> a >> b;
            bool e = checkAnswer(a, b, 2*len);
            if(e) cout << "TAK" << "\n";
            else cout << "NIE" << "\n";
        }
    }
    return 0;
}
