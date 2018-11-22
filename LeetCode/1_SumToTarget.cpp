class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++) {
            m.insert(std::make_pair(nums[i], i));
        }
        for(int i=0; i<nums.size(); i++) {
            auto it = m.find(target-nums[i]);
            if(it != m.end() && it->second != i) {
                return vector<int>({i, it->second});   
            }
        }
    }
};

