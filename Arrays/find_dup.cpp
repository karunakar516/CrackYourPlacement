class Solution {
    public: 
    int findDuplicate(vector < int > & nums) {
        int lo = 1, hi = nums.size() - 1, ans;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2, cnt = 0;
            for (auto i: nums) {
                if (i <= mid) cnt++;
            }
            if (cnt >= mid + 1) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};