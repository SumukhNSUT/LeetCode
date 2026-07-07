class Solution {
    // dp[i][j] => i,j se 0,0 pe aa rha
    // up and left are options
    // top down approach
    private:
    int fn(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp, 
    int n, int m){
        if(i>=0 && j>=0 && grid[i][j]==1) return 0; //obstacle, invalid path

        //base case(reached target)
        if(i==0 && j==0) return 1; // 0,0 se 0,0 tak paths

        if(i<0 || j<0) return 0; //invalid path
        if(dp[i][j] != -1) return dp[i][j];
        int up=fn(i-1,j,grid,dp,n,m);
        int left=fn(i,j-1,grid,dp,n,m);
        dp[i][j]=up+left;
        return dp[i][j];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        // 1 obstacle and 0 pe can move
        return fn(n-1,m-1,obstacleGrid,dp,n,m);
    }
};