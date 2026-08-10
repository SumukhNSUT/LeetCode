class Solution {
private:
    int fn(int row, int col, vector<vector<int>>&mat, vector<vector<int>> &dp){
        int m=mat.size();
        int n=mat[0].size();
        //base case
        if(row==m-1 && col==n-1){
            return 1;
        }

        int d=0;
        int r=0;
        if(dp[row][col] != -1) return dp[row][col];
        //down
        if(row <= m-2 && mat[row+1][col] != 1){
            d=fn(row+1,col,mat,dp);
        }
        //right
        if(col <= n-2 && mat[row][col+1] != 1){
            r=fn(row,col+1,mat,dp);
        }
        return dp[row][col]=d+r;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<int>>dp(m,vector<int>(n, -1));
        return fn(0,0,obstacleGrid,dp);
    }
};