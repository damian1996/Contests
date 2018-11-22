class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> prevOccur;
        int res = 0, curr = 0;
        for(int i=0; i<s.size(); i++) {
            if(prevOccur.count(s[i]) <= 0) {
                curr++;
            }
            else {
                int diff = i - prevOccur[s[i]];
                if(diff > curr) curr++;
                else if(diff <= curr) curr = diff;
            }
            prevOccur[s[i]] = i;
            res = max(res, curr);
        }
        return res;
    }
};
