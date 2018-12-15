#include "bits/stdc++.h"

using namespace std;

namespace teatr {

  bool initialized = false;
  int n;
  vector <int> A;

  void init() {
    if(initialized) return;
    cin >> n;
    A.resize(n);
    for(int i=0; i<n; i++) cin >> A[i];
    initialized = true;
  }

  int GetN() {
    init();
    return n;
  }

  int GetElement(int i) {
    init();
    assert(0 <= i and i < n);
    return A[i];
  }

}


#ifdef __cplusplus
extern "C" {
#endif
int GetN() {
  return teatr::GetN();
}
int GetElement(int i) {
  return teatr::GetElement(i);
}
#ifdef __cplusplus
}
#endif
