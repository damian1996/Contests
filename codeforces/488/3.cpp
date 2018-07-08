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
        pair<float, float> mid;
        mid.st = (sq[wew][0].st + sq[wew][2].st)/2.0;
        mid.nd = (sq[wew][0].nd + sq[wew][2].nd)/2.0;
        if(!(mid.st >= minX && mid.st <= maxX && mid.nd >= minY && mid.nd <= maxY)) {
            return false;
        }
    }
    return true;
}

bool intersectSections(pi x1, pi x2, pi y1, pi y2) {
    if(x1.st == x2.st) {
        if((y1.st<=x1.st && y2.st>=x1.st) || (y1.st>=x1.st && y2.st<=x1.st)) {
          cout << "here st" << x1.st << " " << x1.nd << endl;
          int maxi = (x1.nd < x2.nd) ? x2.nd : x1.nd;
          int mini = (x1.nd > x2.nd) ? x2.nd : x1.nd;
          return true;
        }
    }
    else if(x1.nd == x2.nd) {
        if((y1.nd<=x1.nd && y2.nd>=x1.nd) || (y1.nd>=x1.nd && y2.nd<=x1.nd)) {
          cout << "here nd" << x1.nd << endl;
          int maxi = (x1.st < x2.st) ? x2.st : x1.st;
          int mini = (x1.st > x2.st) ? x2.st : x1.st;
          if((y1.st > ))
          return true;
        }
    }
    cout << "Nope" << endl;
    return false;
}


bool intersect() {
    for(int i=0; i<4; i++) { // boki rownoleglego do osi kwadratu
        for(int j=0; j<4; j++) {
            bool res = intersectSections(sq[0][i], sq[0][(i+1)%4], sq[1][j], sq[1][(j+1)%4]);
            if(res) return true;
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
