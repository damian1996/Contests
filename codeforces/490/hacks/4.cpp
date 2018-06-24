#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define f first
#define s second
#define loop(x,n) for(ll x=0; x<n; x++)
#define extloop(x,y,n) for(ll x=y; x<n; x++)
#define pb push_back
#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k;
    cin>>n>>k;

    ll i=0, j=n-1;

    ll arr[n];

    loop(i,n)	cin>>arr[i];

    while (i<=j && arr[i]<=k)	i++;
    while (j>=i && arr[j]<=k)	j--;

    ll curr=j-i+1;

    ll solved=n-curr;

    cout<<solved<<endl;
}
