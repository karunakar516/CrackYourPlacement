class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n=prices.size();
        int dp[n][2];
        memset(dp,-1,sizeof(dp));
        auto solve=[&](int i,int b,auto&& solve){
            if(i==n) return 0;
            if(dp[i][b]!=-1) return dp[i][b];
            if(!b){
                return dp[i][b]=max(solve(i+1,b,solve),-prices[i]+solve(i+1,1-b,solve));
            }
            else{
                return dp[i][b]=max(solve(i+1,b,solve),prices[i]+solve(i+1,1-b,solve));
            }
        };
        return solve(0,0,solve);
    }
};