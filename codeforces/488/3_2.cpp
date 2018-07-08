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
vector<pair<int, int> > sq[2];
int A[202][202];

bool inside(int zew) {
    int wew = (1-zew);
    int maxX = -200, maxY = -200, minX = 200, minY = 200;
    for(int i=0; i<4; i++) {
        if(sq[zew][i].st > maxX) maxX = sq[zew][i].st;
        if(sq[zew][i].st < minX) minX = sq[zew][i].st;
        if(sq[zew][i].nd > maxY) maxY = sq[zew][i].nd;
        if(sq[zew][i].nd < minY) minY = sq[zew][i].nd;
    }
    if(wew) {
        for(int i=0; i<4; i++) {
            if(!(sq[wew][i].st>=minX && sq[wew][i].st<=maxX)) return false;
            if(!(sq[wew][i].nd>=minY && sq[wew][i].nd<=maxY)) return false;
        }
    } else {
        pair<float, float> mid, mid1;
        mid.st = (sq[wew][0].st + sq[wew][2].st)/2.0;
        mid.nd = (sq[wew][0].nd + sq[wew][2].nd)/2.0;
        mid1.st = (sq[zew][0].st + sq[zew][3].st)/2.0;
        mid1.nd = (sq[zew][0].nd + sq[zew][3].nd)/2.0;
        mid.st = mid.st - mid1.st;
        mid.nd = mid.nd - mid1.nd;
        float r = (sq[zew][3].st - sq[zew][0].st)/2;
        if((fabs(mid.st) + fabs(mid.nd)) > r) return false;
    }
    return true;
}

bool intersect() {
    for(int i=0; i<4; i++) {
        sq[0][i].st += 100;
        sq[0][i].nd += 100;
        sq[1][i].st += 100;
        sq[1][i].nd += 100;
    }
    for(int i=sq[0][0].st; i<=sq[0][3].st; i++) {
        for(int j=sq[0][0].nd; j<=sq[0][3].nd; j++) {
            A[i][j] = 1;
        }
    }
    int sideSize = sq[1][1].st - sq[1][0].st;
    int i = sq[1][0].st, j = sq[1][0].nd, r = sq[1][0].nd, p;

    A[i][j]++;
    if(A[i][j]>=2) {
      //cout << i << " " << j << endl;
      return true;
    }
    for(int k=0; k<sideSize; k++) {
        i++;
        j++;
        r--;
        A[i][j]++;
        if(A[i][j]>=2) {
          //cout << i << " " << j << endl;
          return true;
        }
        A[i][r]++;
        if(A[i][r]>=2) {
          //cout << i << " " << r << endl;
          return true;
        }
    }
    i = sq[1][1].st, p = sq[1][2].st, r = sq[1][2].nd, j = sq[1][1].nd;
    for(int k=0; k<sideSize; k++) {
        i++;
        p++;
        j++;
        r--;
        A[i][j]++;
        if(A[i][j]>=2) {
          //cout << i << " " << j << endl;
          return true;
        }
        if(p == sq[1][3].st && r == sq[1][3].nd) break;
        A[p][r]++;
        if(A[p][r]>=2) {
          //cout << p << " " << r << endl;
          return true;
        }
    }
    return false;
}

int main() {
  std::ios::sync_with_stdio(false);
  int n, m, t;
  for(int i=0; i<2; i++) {
    sq[i].resize(4);
    for(int j=0; j<4; j++) {
      cin >> sq[i][j].st;
      cin >> sq[i][j].nd;
    }
  }

  int cross1 = (sq[0][2].st-sq[0][0].st)*(sq[0][2].st-sq[0][0].st) + (sq[0][2].nd-sq[0][0].nd)*(sq[0][2].nd-sq[0][0].nd);
  int cross2 = (sq[1][2].st-sq[1][0].st)*(sq[1][2].st-sq[1][0].st) + (sq[1][2].nd-sq[1][0].nd)*(sq[1][2].nd-sq[1][0].nd);
  sort(sq[0].begin(), sq[0].end());
  sort(sq[1].begin(), sq[1].end());
  bool in = (cross1>cross2) ? inside(0) : inside(1);

  if(in) {
    cout << "YES" << endl;
  } else {
    if(intersect()) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
