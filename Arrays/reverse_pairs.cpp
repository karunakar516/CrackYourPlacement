class Solution {
    public: 
    int reversePairs(vector < int > & nums) {
        vector < int > dummy;
        int ans = 0;
        for (auto i: nums) {
            int idx = upper_bound(dummy.begin(), dummy.end(), 2 LL * i) - dummy.begin();
            ans += dummy.size() - idx;
            idx = lower_bound(dummy.begin(), dummy.end(), i) - dummy.begin();
            if (idx == dummy.size()) dummy.push_back(i);
            else dummy.insert(dummy.begin() + idx, i);
        }
        return ans;
    }
};