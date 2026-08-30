class Solution {
private:
    int fn(int row, int col, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(row<0 || col <0) return 0; //invalid path
        if(grid[row][col] == 1) return 0; //invalid path
        if(row==0 && col==0) return 1;
        
        if(dp[row][col] != -1) return dp[row][col];

        int up=fn(row-1,col,grid,dp);
        int left=fn(row,col-1,grid,dp);

        return dp[row][col]=up+left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //[n-1,m-1] se [0,0] pe aa rha hu
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1] == 1) return 0; //cant reach
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return fn(n-1,m-1,obstacleGrid,dp);
    }
};