#define ub upper_bound
#define ll long long
#define lb lower_bound
#define all(a) a.begin(), a.end()
#define bn(a) a.begin()
class Solution {
    public:
    vector < vector < int >> fourSum(vector < int > & nums, int target) {
        int n = nums.size();
        vector < vector < int >> ans;
        sort(all(nums));
        for (int a = 0; a < n;) {
            for (int b = a + 1; b < n;) {
                int c = b + 1, d = n - 1;
                while (c < d) {
                    long long curr = (ll) nums[a] + (ll) nums[b] + (ll) nums[c] + (ll) nums[d];
                    if (curr == target) {
                        ans.push_back({
                            nums[a],
                            nums[b],
                            nums[c],
                            nums[d]
                        });
                        c = ub(all(nums), nums[c]) - bn(nums);
                        d = lb(all(nums), nums[d]) - bn(nums) - 1;
                    }
                    else if (curr < target)
                        c = ub(all(nums), nums[c]) - bn(nums);
                    else 
                        d = lb(all(nums), nums[d]) - bn(nums) - 1;
                }
                b = ub(all(nums), nums[b]) - bn(nums);
            }
            a = ub(all(nums), nums[a]) - bn(nums);
        }
        return ans;
    }
};