#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define FWD(i, a, b) for(int i = a; i < b; i++)
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define pi pair<int, int>
#define mp(a, b) make_pair(a,b)
using namespace std;
typedef long long ll;
const ll N = 1e9;


int main() {
  std::ios::sync_with_stdio(false);
  int n, k, ai;
  cin >> n >> k;
  vi pixels;
  vi result;
  pixels.resize(n);
  result.resize(n);
  for(int i=0; i<n; i++) {
      cin >> pixels[i];
  }
  int tab[256];
  for(int i=0; i<256; i++)
    tab[i] = -1;
  for(int i=0; i<n; i++) {

  }
  for(int i=0; i<n; i++) {
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}


int tab[256] = {-1, ...};
for(int i = 0; i < n; i) {
    int v = p[i];
    int j = 0;
    // dopóki nie zeszliśmy niżej niż k, nie wyszliśmy poza tablice i nie weszliśmy na inną grupę
    while(j < k && v-j >= 0 && p[v-j] == -1) ++j;
    if(j) {
     //ten piksel nie ma przydzielonej grupy, tworzymy nową
     int b = 0;
     int g = v-j;
     //ustawiamy ten piksel i dopóki możemy to wyżej (tamtym wyższym pikselom też się opłaca żeby miały tę grupe)
     while(b < k && v-j+b < 256 && p[v-j+b] == -1) p[v-j+b] = g, ++b;
    }
    wynik[i] = p[v-j];
}
