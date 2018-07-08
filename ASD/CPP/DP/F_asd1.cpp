#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int z, n, len;
    long long sum = 0;
    int *height;
    long long *subseq;
    cin >> z;
    for(int zz=0; zz<z; zz++)
    {
        sum = 0;
        len = -1;
        cin >> n;
        height = new int[n+1];
        height[0] = 0;
        subseq = new long long[n+1];
        subseq[0] = 0;
        for(int i=1; i<=n; i++)
            cin >> height[i];
        for(int i=1; i<=n; i++)
            sum += height[i];
        sum+=1;
        for(int i=1; i<=n; i++)
            subseq[i] = sum;
        for(int i=1; i<=n; i++)
        {
            int m, l, r;
            l = 1, r = n+1;
            while(l<r)
            {
                m = (l+r)/2;
                if(height[i]<=subseq[m])
                    r = m;
                else
                    l = m+1;
            }
            m = l;
            subseq[m] = height[i];
        }
        for(int i=1; i<=n; i++)
        {
            if(subseq[i] == sum)
            {
                len = i-1;
                break;
            }
        }
        if(len == -1)
           len = n;
        cout << n-len << endl;
        delete [] subseq;
        delete [] height;
    }
    return 0;
}
