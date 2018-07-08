#include <iostream>
#include <algorithm>
using namespace std;
int maximum(int i, int *filary, int *dp)
{
    int tmp1 = dp[i-1];
    int tmp2 = filary[i] + dp[i-2];
    int tmp3 = filary[i] + filary[i-1] + dp[i-3];
    if(tmp1>tmp2)
    {
        if(tmp1 > tmp3)
            return tmp1;
        else
            return tmp3;
    }
    else
    {
        if(tmp2>tmp3)
            return tmp2;
        else
            return tmp3;
    }
}
int main()
{
    int Z, N;
    int *filary;
    cin >> Z;
    for(int zz=0; zz<Z; zz++)
    {
        cin >> N;
        int *dp = new int[N+1];
        filary = new int[N+1];
        for(int i=0; i<=N; i++)
        {
            dp[i] = 0;
        }
        for(int i=1; i<=N; i++)
        {
            cin >> filary[i];
            if(i==1)
            {
                dp[i] = filary[i];
            }
            else if(i==2)
            {
                dp[i] = filary[i] + dp[i-1];
            }
            else
            {
                dp[i] = maximum(i, filary, dp);
            }
        }
        cout << dp[N] << endl;
        delete [] dp;
        delete [] filary;
    }
    return 0;
}

