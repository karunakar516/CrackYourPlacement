class Solution {
    public:
    vector < int > countSmaller(vector < int > & nums) {
        int n = nums.size();
        vector < int > dup, ans(n);
        for (int i = n - 1; i >= 0; i--) {
            auto idx = lower_bound(dup.begin(), dup.end(), nums[i]) - dup.begin();
            if (idx == dup.size()) dup.push_back(nums[i]);
            else dup.insert(dup.begin() + idx, nums[i]);
            ans[i] = idx;
        }
        return ans;
    }
};