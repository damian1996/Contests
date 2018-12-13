#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    unordered_map<char, bool> letters;
    const int SPOL = 0, SAMO = 1;
    for(int i=0; i<26; i++) {
        letters['a' + 1] = SPOL;
    }
    letters['a'] = SAMO; letters['e'] = SAMO; letters['i'] = SAMO;
    letters['o'] = SAMO; letters['u'] = SAMO; letters['y'] = SAMO;
    string s;
    cin >> s;
    long long result = 0;
    int cnt[2] = {0, 0};
    int siz = s.size(), lastTraf = -1;
    char prev = '/';
    for(int i=0; i<siz; i++) {
        int let = letters[s[i]];
        cnt[let]++;
        if(letters[prev] == let && cnt[let] >= 3) {
            result += (i - 1);
            if(lastTraf != -1) {
                int a = lastTraf - 2, b = i - lastTraf - 1;
                result += (b + a*b);
            }
            lastTraf = i;
        } else {
            cnt[1 - let] = 0;
        }
        prev = s[i];
    }
    if(lastTraf != -1) {
        int b = siz - 1 - lastTraf, a = lastTraf - 2;
        result += (b + a*b);
    }
    cout << result << endl;
    return 0;
}
