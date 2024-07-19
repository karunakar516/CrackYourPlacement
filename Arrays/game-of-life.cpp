class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> dummy=board;
        auto score=[&](int i,int j){
            int ans=0;
            for(int di=-1;di<=1;di++){
                for(int dj=-1;dj<=1;dj++){
                    if(di==0 and dj==0) continue;
                    if(i+di>=0 and i+di<board.size() and j+dj>=0 and j+dj<board[0].size()) ans+=dummy[i+di][j+dj];
                }
            }
            return ans;
        };
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int sc=score(i,j);
                if(board[i][j]==1){
                    if(sc<2 or sc>3) board[i][j]=0;
                }
                else if(sc==3) board[i][j]=1;
            }
        }
    }
};