#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define BCK(i, n) for(int i = n-1; i >= 0; i--)
#define FWD(i, a, b) for(int i = a; i < b; i++)
#define pb push_back
#define st first
#define nd second
#define vi vector<int>
#define vll vector<long long>
#define pi pair<int, int>
#define pll pair<long long, long long>
#define vpi vector<pi>
#define vpll vector<pll>
#define mp(a, b) make_pair(a,b)
using namespace std;
typedef long long LL;
typedef double ld;
const LL p = 1000000007;


int main() {
    long long n, sum = 0;
    cin >> n;
    vector<long long> vec(n);
    vector<pair<LL, LL>> edges;
    for(int i=0; i<n; i++) cin >> vec[i];
    std::sort(vec.begin(), vec.end());
    int leaves = 0, maxi = 0, sum = 0, nodes = 0;
    for(int i=0; vec[i] < 2; i++) if(vec[i] == 1) leaves++;
    for(int i=0; vec[i]<=leaves; i++) {
        nodes++;
        if(vec[i] <= leaves && vec[i] > maxi) {
            maxi = vec[i];
        }
    }
    for(int i=0; vec[i] <= maxi; i++) {
        sum += vec[i];
        if(sum == 2*i)
            cout << "TRUE" << endl;
    }

    for(int i=0; i<n; i++) {

    }
    for(int i=0; i<edges.size(); i++) {
        printf("%d %d\n", edges[i].first+1, edges[i].second+1);    
    }
    return 0;
}