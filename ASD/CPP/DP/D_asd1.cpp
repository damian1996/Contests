#include<iostream>
#include<string>
const char up = '0';
const char letf = '1';
const char eq = '2';
using namespace std;
void tempSubstr(char **subst, string a, int aLen, int bLen)
{
      if(aLen==0 || bLen==0)
              return;
    if(subst[aLen][bLen]==eq)
      {
              tempSubstr(subst, a, aLen-1, bLen-1);
              cout << a[aLen-1];
      }
      else if(subst[aLen][bLen]==up)
      {
              tempSubstr(subst, a, aLen-1, bLen);
      }
      else
      {
              tempSubstr(subst, a, aLen, bLen-1);
      }
}
int main()
{
      ios_base::sync_with_stdio(0);
      int Z;
      short m, n;
      short **result;
    char **subst;
      string a, b;
      cin >> Z;
      for(int z=0; z<Z; z++)
      {
        cin >> a >> b;
        m = a.length();
        n = b.length();
        result = new short *[m+1];
        for(int i=0; i<=m; i++)
                result[i] = new short[n+1];
        subst = new char*[m+1];
        for(int i=0; i<=m; i++)
                subst[i] = new char[n+1];

        for(int i=1; i<=m; i++)
                result[i][0] = 0;
        for(int i=0; i<=n; i++)
                result[0][i] = 0;
        for(int i=1; i<=m; i++)
        {
                for(int j=1; j<=n; j++)
                {
                        if(a[i-1]==b[j-1])
                        {
                                result[i][j] = result[i-1][j-1]+1;
                                subst[i][j] = eq;
                        }
                        else if(result[i-1][j]>=result[i][j-1])
              {
                                result[i][j] = result[i-1][j];
                                subst[i][j] = up;
                        }
                        else
                        {
                                result[i][j] = result[i][j-1];
                                subst[i][j] = letf;
                        }
                }
        }
        cout << result[m][n] << endl;
      tempSubstr(subst, a, m, n);
      cout << endl;
        for(int i=0; i<=m; i++)
        delete [] subst[i];
      delete [] subst;
        for(int i=0; i<=m; i++)
        delete [] result[i];
      delete [] result;
      }
      return 0;
}
