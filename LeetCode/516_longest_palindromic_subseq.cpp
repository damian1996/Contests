class Solution {
public:
    int LPS(string& s, int a, int b, vector<vector<int>>& lps) {
        if(a > b) return 0;
        if(a == b) return 1;
        if(s[a] == s[b]) {
            if(lps[a+1][b-1] == 0) {
                lps[a+1][b-1] = LPS(s, a+1, b-1, lps);            
            } 
            return 2 + lps[a+1][b-1];
        } else {
            if(lps[a][b-1] == 0) {
                lps[a][b-1] = LPS(s, a, b-1, lps);            
            } 
            if(lps[a+1][b] == 0) {
                lps[a+1][b] = LPS(s, a+1, b, lps);            
            }
            return max(lps[a+1][b], lps[a][b-1]);
        }
    }
    
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> lps(s.size());
        for(int i=0; i<s.size(); i++) {
            lps[i].resize(s.size());   
            //fill(lps[i].begin(), lps[i].end(), 0);
        }
        int a = 0, b = s.size()-1;
        if(a == b) return 1;
        
        if(s[a] == s[b]) {
            return 2 + LPS(s, a+1, b-1, lps);
        } else {
            return max(1, max(LPS(s, a, b-1, lps), LPS(s, a+1, b, lps)));
        }
    }
};