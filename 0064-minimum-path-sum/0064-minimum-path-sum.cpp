class Solution {
private:
    int fn(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        //base case
        int m=grid.size();
        int n=grid[0].size();
        if(row==m-1 && col==n-1){
            return grid[row][col];
        }
        if(dp[row][col] != -1) return dp[row][col];
        int d=1e9;
        int r=1e9;
        if(row <= m-2){
            d=grid[row][col]+fn(row+1,col,grid,dp);
        }
        if(col <= n-2){
            r=grid[row][col]+fn(row,col+1,grid,dp);
        }
        return dp[row][col]=min(d,r);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fn(0,0,grid,dp);
    }
};