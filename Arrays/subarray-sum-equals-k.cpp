class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0]=1;
        int ans=0,s=0;
        for(auto i:nums){
            s+=i;
            ans+=mp[s-k];
            mp[s]++;
        }
        return ans;
    }
};