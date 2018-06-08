#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin>>k;
    vector<vector<ll>>a(k);
    vector<ll>S(k);
    unordered_map<ll,unordered_set<int>>dp;
    for(int i=0; i<k; i++)
    {
        int n;
        cin>>n;
        a[i]=vector<ll>(n);
        for(int j=0; j<n; j++)
        {
            cin>>a[i][j];
            S[i]+=a[i][j];
        }
        for(int j=0; j<n; j++)
        {
            dp[S[i]-a[i][j]].insert(i);
        }
    }

    for(auto i:dp)
    {
        if(i.second.size()>=2)
        {
            auto it=i.second.begin();
            int x1=*it;
            it++;
            int x2=*it;
            cout<<"YES\n";
            cout<<x1+1<<' '<<find(a[x1].begin(),a[x1].end(),S[x1]-i.first)-a[x1].begin()+1<<'\n';
            cout<<x2+1<<' '<<find(a[x2].begin(),a[x2].end(),S[x2]-i.first)-a[x2].begin()+1<<'\n';
            return 0;
        }
    }
    cout<<"NO\n";
    return 0;
}
