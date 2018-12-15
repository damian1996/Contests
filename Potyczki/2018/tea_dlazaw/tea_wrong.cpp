// Jedna instancja wypisuje maksymalny wzrost.

#include "message.h"
#include "teatr.h"
#include "bits/stdc++.h"

using namespace std;

int main() {
  if(MyNodeId() != 0) return 0;
  int n = GetN();
  int maxi = 0;
  for(int i=0; i<n; i++) maxi = max(maxi, GetElement(i));
  cout << maxi << "\n";
}
