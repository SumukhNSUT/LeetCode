class Solution {
private:
    int fn(int row, int col, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(row <0 || col<0) return 1e9; //invalid path
        if(row==0 && col==0) return grid[0][0];

        if(dp[row][col] != -1) return dp[row][col];

        int up=grid[row][col]+fn(row-1,col,grid,dp);
        int left=grid[row][col]+fn(row,col-1,grid,dp);
        
        dp[row][col]=min(left,up);
        return dp[row][col];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        //[n-1,m-1] se [0,0] pe jaa rha hu
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fn(n-1,m-1,grid,dp);
    }
};