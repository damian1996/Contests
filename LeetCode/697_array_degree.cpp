class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        vector<int> to_sort;
        std::copy(nums.begin(), nums.end(), std::back_inserter(to_sort));
        sort(to_sort.begin(), to_sort.end());
        //for_each(begin(to_sort), end(to_sort), [](int el) {cout << el << endl;});
        int biggest = to_sort[0], cnt = 1;
        int tmp_cnt = 1;
        for(int i=1; i<to_sort.size(); i++) {
            if(to_sort[i-1] != to_sort[i]) {
                if(cnt < tmp_cnt) {
                    cnt = tmp_cnt;
                    biggest = to_sort[i-1];
                }
                tmp_cnt = 1;
            } else {
                tmp_cnt++;
            }
        }
        auto fr = std::find(nums.begin(), nums.end(), biggest);
        auto sec = std::find(nums.rbegin(), nums.rend(), biggest);
        //cout << std::distance(nums.begin(), fr) << endl;
        //cout << std::distance(nums.rbegin(), sec) << endl;
        return nums.size() - std::distance(nums.begin(), fr) - std::distance(nums.rbegin(), sec);
    }
};