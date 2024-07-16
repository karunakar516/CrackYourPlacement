class Solution {
    public: 
    vector < vector < int >> threeSum(vector < int > & nums) {
        vector < vector < int >> ans;
        sort(nums.begin(), nums.end());
        for (int ind = 0; ind < nums.size();) {
            int i = ind + 1, j = nums.size() - 1;
            while (i < j) {
                if (nums[ind] + nums[i] + nums[j] == 0) {
                    ans.push_back({
                        nums[ind],
                        nums[i],
                        nums[j]
                    });
                    j = lower_bound(nums.begin(), nums.end(), nums[j]) - nums.begin() - 1;
                    i = upper_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
                }
                else if (nums[ind] + nums[i] + nums[j] > 0) {
                    j = lower_bound(nums.begin(), nums.end(), nums[j]) - nums.begin() - 1;
                }
                else {
                    i = upper_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
                }
            }
            ind = upper_bound(nums.begin(), nums.end(), nums[ind]) - nums.begin();
        }
        return ans;
    }
};