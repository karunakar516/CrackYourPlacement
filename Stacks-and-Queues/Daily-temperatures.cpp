class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<int> ms;
        int n=arr.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(ms.size() and arr[ms.top()]<=arr[i]) ms.pop();
            if(ms.size()) ans[i]=ms.top()-i;
            ms.push(i);
        }
        return ans;
    }
};