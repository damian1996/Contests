/*
sum(P) - sum(N) = target
sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
2 * sum(P) = target + sum(nums)

Find a subset P of nums such that sum(P) = (target + sum(nums)) / 2
*/

// fast algorithm




// poor performance
class Solution {
public:
    void DFS(int i, int sum, int S, vector<int>& V, vector<vector<int>>& G, int& cnt) {
        sum += V[i];
        if(G[i].size() == 0) {
            if(sum == S) cnt++;
        }
        for(auto& p : G[i]) {
            DFS(p, sum, S, V, G, cnt);
        }        
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<vector<int>> G(2*nums.size());
        vector<int> V(2*nums.size());
        for(int i=0; i<nums.size(); i++) {
            V[2*i] = nums[i];
            V[2*i + 1] = -nums[i];
        }
        for(int i=0; i<nums.size()-1; i++) {
            G[2*i].push_back(2*(i+1));
            G[2*i+1].push_back(2*(i+1));
            G[2*i].push_back(2*(i+1)+1);
            G[2*i+1].push_back(2*(i+1)+1);
        }
        int cnt = 0;
        DFS(0, 0, S, V, G, cnt);
        DFS(1, 0, S, V, G, cnt);
        return cnt;        
    }
};