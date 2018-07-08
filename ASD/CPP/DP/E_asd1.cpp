#include <iostream>
#include <algorithm>
const long long MAX = 100000000000000001;
using namespace std;
struct Point
{
      int x, y;
};
long long dist(Point p1, Point p2)
{
      return ((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
}
long long cost(Point *points, int i, int j, int k)
{
      Point p1 = points[i], p2 = points[k], p3 = points[j];
      long long result = 0;
      if(i+1<k)
         result += dist(p1, p2);
      if(k+1<j)
         result += dist(p2, p3);
      return result;
}
long long MWT(Point *points, int n, int **s)
{
      if(n<3)
         return 0;
      long long matrix[n][n];
      for(int d=0; d<n; d++)
         for(int i=0; i<n; i++)
            matrix[d][i] = 0;
      for(int d=2; d<n; d++)
      {
              for(int i=0; i<n; i++)
              {
                  int j=(i+d)%n;
                              matrix[i][j] = MAX;
                              for(int k=i+1; k<j; ++k)
                              {
                                  long long x = matrix[i][k] + matrix[k][j] + cost(points,i,j,k);
                                              if(matrix[i][j] > x)
                                  {
                                              matrix[i][j] = x;
                                              s[i][j] = k;
                                      }
                              }
              }
      }
    return matrix[0][n-1];
}
void print(int start, int end, int **s)
{
      if(start+1<end)
      {
              int root = s[start][end];
              if(start+1<root)
            cout << start << " " << root << " ";
          if(root+1 < end)
            cout << root << " " << end << " ";
              print(start, root, s);
              print(root, end, s);
      }
      else
         return;
}
int main()
{
      ios_base::sync_with_stdio(0);
    int z, n;
    int **s;
    cin >> z;
    for(int zz=0; zz<z; zz++)
    {
              cin >> n;
              Point * points = new Point[n];
              s = new int*[n];
              for(int j = 0; j<n; j++)
                 s[j] = new int[n];

              for(int i=0; i<n; i++)
              {
             cin >> points[i].x >> points[i].y;
              }
              for(int i=0; i<n; i++)
                 for(int j=0; j<n; j++)
                    s[i][j] = 0;
              long long result = MWT(points, n, s);
              cout << result << " ";
    print(0, n-1, s);
              cout << endl;
              for(int i=0; i<n; i++)
                 delete [] s[i];
              delete [] s;
              delete [] points;
      }
    return 0;
}
