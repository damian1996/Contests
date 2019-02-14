/*
 * Complete the 'shortestSubstring' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

bool constainsAllChars(string& s, int a, int b, vector<char>& allChars, unordered_map<char,int>& m) 
{
    cout << a << " " << b << endl;
    vector<int> cnt(allChars.size());
    fill(cnt.begin(), cnt.end(), 0);
    int allAre = 0;
    for(int i=a; i<=b; i++) {
        if(cnt[m[s[i]]] == 0) {
            cnt[m[s[i]]]++;
            allAre++;
        }
    }
    return allAre == allChars.size();
}

int shortestSubstring(string s) 
{
    vector<char> v;
    std::copy(s.begin(), s.end(), std::back_inserter(v));
    std::sort(std::begin(v), std::end(v));
    auto last = std::unique(v.begin(), v.end());
    //v.erase(last, v.end()); 
    v.resize(std::distance(std::begin(v), last));
    for_each(begin(v), end(v), [](char c) { cout << c << " ";} );
    cout << endl;
    unordered_map<char, int> unq;
    for(int i=0; i<v.size(); i++) {
        unq.insert({v[i], i});
    }
    int a = 0, b = 0;
    vector<int> occ(v.size());
    fill(occ.begin(), occ.end(), 0);
    occ[unq[s[0]]] = 1;
    if(v.size() == 1) return 1;
    int mini{std::numeric_limits<int>::max()};
    for(int i=1; i<s.size(); i++) {
        occ[unq[s[i]]]++;
        if (occ[unq[s[i]]] > 1 && s[i] == s[a]) {
            occ[unq[s[i]]]--;
            a++;
        }
        while(occ[unq[s[a]]] > 1) {
            a++;
            occ[unq[s[a]]]--;
        }    
        b++;
        if(constainsAllChars(s, a, b, v, unq)) {
            mini = min(mini, b-a+1);
        }
    }
    
    return mini;
}

/*

def shortestSubstring(s):
    unq = list(set(s))
    d = {}
    for i, u in enumerate(unq):
        d[u] = i
    occ = [0] * len(unq)
    test = [0] * len(unq)
    a = 0
    b = 0
    occ[d[s[0]]] = 1
    test[d[s[0]]] = 1
    allAre = 1
    mini = 100000000000000
    for i, c in enumerate(s[1:]):
        occ[d[c]] += 1
        test[d[c]] += 1
        if test[d[c]] == 1:
            allAre += 1
            
        if occ[d[c]] > 1 and c == s[a]:
            a += 1
            occ[d[c]] -= 1
            test[d[c]] -= 1
        
        while occ[d[s[a]]] > 1:
            occ[d[s[a]]] -= 1
            test[d[s[a]]] -= 1
            a += 1
        b += 1
        if allAre == len(unq):
            mini = min([mini, b-a+1])
    return mini
*/