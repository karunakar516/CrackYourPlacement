class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        auto ans=[&](int i,int j,int k,auto &&ans){
            if(k==word.length()) return 1;
            if(i<0 or i>=n or j<0 or j>=m or vis[i][j]==1 or board[i][j]!=word[k])
                return 0;
            vis[i][j]=1;
            if(ans(i+1,j,k+1,ans)||ans(i-1,j,k+1,ans)||ans(i,j+1,k+1,ans)||ans(i,j-1,k+1,ans)) return 1;
            vis[i][j]=0;
            return 0;
        };
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ans(i,j,0,ans)) return 1;
            }
        }
        return 0;
    }
};