#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
typedef std::vector<char> vec;
vec words[26*26+1];


string L2(ll N, bool& createNewWord) {
  char out[3];
  for(int j=0; j<N; j++) {
      for(int k=0; k<N; k++) {
          bool was = false;
          out[0] = words[j][0];
          out[1] = words[k][1];
          for(int l=0; l<N; l++) {
              if(words[l][0]==out[0] && words[l][1]==out[1]) {
                 was = true;
                 break;
              }
          }
          if(!was) {
            string str(out, 2);
            createNewWord = true;
            return str;
          }
      }
  }
  string str(out, 2);
  createNewWord = false;
  return str;
}

int main() {
  std::ios::sync_with_stdio(false);
  ll T, N, L;
  char letter;
  cin >> T;
  for(int i=0; i<T; i++) {
    bool createNewWord = false;
    cin >> N >> L;
    string out;
    for(int j=0; j<N; j++) {
      words[j].clear();
      for(int k=0; k<L; k++) {
        cin >> letter;
        words[j].push_back(letter);
      }
    }

    if(L==2) {
      out = L2(N, createNewWord);
    } else if(L==1) {
      createNewWord = false;
    } else {
      createNewWord = false;
    }

    if(createNewWord) 
       cout << "Case #" << i << ": " << out << "\n";
    else 
      cout << "Case #" << i << ": -" << "\n";
  }

  return 0;
}
