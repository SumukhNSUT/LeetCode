class Solution {
private:
    int fn(int row, int col, vector<vector<int>>&dp){
        if(row < 0 || col < 0) return 0;
        //[row,col] se [0,0] pe aana hai
        if(row==0 && col == 0){
            return 1;
        }

        if(dp[row][col] != -1) return dp[row][col];

        int up=fn(row-1,col,dp);
        int left=fn(row,col-1,dp);
        return dp[row][col]=up+left;
    }
public:
    int uniquePaths(int m, int n) {
        //(m-1,n-1) se (0,0) pe aa rha hu
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fn(m-1,n-1,dp);
    }
};