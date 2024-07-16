class Solution {
    public: vector < int > countSmaller(vector < int > & nums) {
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

//Above Code's Time Complexity is O(n**2) still it gave AC the below approach uses O(nlogn) TC

#include <iostream>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
template < typename T >
    using ordered_multiset = tree < pair < T, int > , null_type, less < pair < T, int >> , rb_tree_tag, tree_order_statistics_node_update > ;

class Solution {
    public: 
    vector < int > countSmaller(vector < int > & nums) {
        int n = nums.size();
        vector < int > ans(n);
        ordered_multiset < int > ds;
        for (int i = n - 1; i >= 0; i--) {
            ds.insert({
                nums[i],
                i
            });
            ans[i] = ds.order_of_key({
                nums[i],
                0
            });
        }
        return ans;
    }
};