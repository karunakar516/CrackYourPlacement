class Solution {
    public: 
    int minMoves2(vector < int > & nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (n & 1) {
            int x = nums[n / 2], ans = 0;
            for (auto i: nums) ans += abs(i - x);
            return ans;
        }
        else {
            int x = nums[n / 2], y = nums[n / 2 - 1], ans1 = 0, ans2 = 0;
            for (auto i: nums) {
                ans1 += abs(i - x);
                ans2 += abs(i - y);
            }
            return min(ans1, ans2);
        }
    }
};