#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int z, n, B;
    int *s;
    int *v;
    int **matrix;
    cin >> z;
    for(int zz=0; zz<z; zz++)
    {
        cin >> n >> B;
        s = new int[n+1];
        v = new int[n+1];
        matrix = new int*[n+1];
        for(int i=0; i<=n; i++)
        {
            matrix[i] = new int[B+1];
        }
        s[0] = 0;
        v[0] = 0;
        for(int i=1; i<=n; i++)
        {
            cin >> s[i] >> v[i];
        }
        for(int k=0; k<=B; k++)
        {
            matrix[0][k] = 0;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=B; j++)
            {
                if(j-s[i]>=0)
                   matrix[i][j] = max(matrix[i-1][j], (v[i]+matrix[i-1][j-s[i]]));
                          else
                                      matrix[i][j] = matrix[i-1][j];
            }
        }
        cout << matrix[n][B] << endl;
        for(int i=0; i<n+1; i++)
            delete [] matrix[i];
        delete [] matrix;
        delete [] v;
        delete [] s;
    }
    return 0;
}
