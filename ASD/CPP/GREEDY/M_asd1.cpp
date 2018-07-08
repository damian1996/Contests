#include <iostream>
#include <utility>
#include <set>
using namespace std;
const int N = 1000000;
const int K = 1000;
const int Infty = 1000001;
int data[N+1];
int temp[N+1];
int occur[N+1];
int main()
{
      ios_base::sync_with_stdio(false);
      temp[0] = 0;
      data[0] = 0;
      int z, k, m, n, result;
      cin >> z;
      for(int zz=0; zz<z; zz++)
      {
              set< pair<int, int> > s;
              set< pair<int, int> >::iterator it;
              set< pair<int, int> >::iterator ite;
              result = 0;
              cin >> k >> n >> m;
              for(int i=1; i<m+1; i++)
                      cin >> data[i];
              for(int i=1; i<n+1; i++)
                      temp[i] = Infty;
              for(int i=1; i<m+1; i++)
                      occur[i] = 0;
              for(int i=m; i>0; i--)
              {
                      occur[i] = temp[data[i]];
                      temp[data[i]] = i;
              }
              for(int i=1; i<m+1; i++)
          {
                      int tmp = s.size();
                      it = s.find(make_pair(i, data[i]));
                      ite = s.end();
                      if(ite!=it)
                      {
                              s.erase(make_pair(i, data[i]));
                              s.insert(make_pair(occur[i], data[i]));
                      }
                      else
                      {
                              if(tmp<k)
                              {
                                      s.insert(make_pair(occur[i], data[i]));
                              }
                              else
                              {
                                      set< pair<int, int> >::iterator er;
                                      er = --s.end();
                                      s.erase(er);
                                      s.insert(make_pair(occur[i], data[i]));
                              }
                              result++;
                      }
              }
              cout << result << endl;
      }
      return 0;
}
