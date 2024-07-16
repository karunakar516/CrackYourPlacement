class NumArray {
    public: 
    vector < int > prefsum;
    NumArray(vector < int > & nums) {
        prefsum = nums;
        int n = nums.size();
        for (int i = 1; i < n; i++) prefsum[i] += prefsum[i - 1];
    }

    int sumRange(int left, int right) {
        if (left == 0) return prefsum[right];
        return prefsum[right] - prefsum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */