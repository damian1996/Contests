class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //for_each(nums.begin(), nums.end(),[](int i){ std::cout << i << ' '; });
        if(nums.size() == 0) return 0;
        int free = -1, prev = nums[0], unqcnt = 1;
        for(int i=1; i<nums.size(); i++) {
            if(prev != nums[i]) {
                unqcnt++;
                prev = nums[i];
                if(free>0) {
                    nums[free] = prev;
                    free++;
                }
            } else {
                if(free == -1) {
                    free = i;
                }
            }
        }
        nums.erase(nums.begin() + unqcnt, nums.end()); 
        return unqcnt;
    }
};

