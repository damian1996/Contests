#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define N 200
#define M 40000

string city[N+1];
vector< pair< string, int> > G[N+1];
unordered_map< string, int> H;
long long result[N+1][N+1];

void floydWarshall(int n, long long inf)
{
    for(int i=1; i<=n; i++)
    {
        vector< pair< string, int> >::iterator it;
        for(it = G[H[city[i]]].begin(); it != G[H[city[i]]].end(); ++it)
        {
            result[i][H[(*it).first]] = (*it).second;
        }
    }
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(result[i][k]==inf || result[k][j]==inf)
                    continue;
                if(result[i][j] > result[i][k] + result[k][j])
                    result[i][j] =  result[i][k] + result[k][j];
            }
        }
    }
}

int main()
{
    //std::ios_base::sync_with_stdio(false);
    int n, m, z, way;
    string townStart, townEnd;
    long long inf = 0;
    cin >> z;
    for(int zz=0; zz<z; zz++)
    {
        cin >> n;
        for(int i=1; i<=n; i++)
        {
            cin >> city[i];
            H[city[i]] = i;
        }
        cin >> m;
        for(int i=0; i<m; i++)
        {
            cin >> townStart >> townEnd >> way;
            G[H[townStart]].push_back(make_pair(townEnd, way));
            G[H[townEnd]].push_back(make_pair(townStart, way));
            inf += way;
        }
        inf+=1;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i==j) result[i][j]=0;
                else result[i][j] = inf;
            }
        }
        floydWarshall(n, inf);

        for(int i=0; i<=n; i++){
          if(i==0) printf("          ");
          else printf("%12s", city[i].c_str());
        }
        cout << endl;
        for (int i = 1; i <= n; i++)
        {
            printf("%10s", city[i].c_str());
            for (int j = 1; j <= n; j++)
            {
              printf("%12lld", result[i][j]);
            }
            cout << endl;
        }

        for(int i=1; i<=n; i++)
        {
            G[H[city[i]]].clear();
        }
        H.clear();
    }
    return 0;
}
