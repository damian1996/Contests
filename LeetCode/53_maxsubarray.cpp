class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> sums(nums.size());
        fill(begin(sums), end(sums), 0);
        sums[0] = nums[0];
        for(int i=1; i<sums.size(); i++) {
            sums[i] = max(sums[i-1] + nums[i], nums[i]);
        }
        return *max_element(sums.begin(), sums.end());
    }
};