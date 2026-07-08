class Solution {
    int fn(int i, int j, int n, int m, vector<vector<int>>&grid,
    vector<vector<int>>&dp){
        //base case
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return INT_MAX;

        //for general i, j
        if(dp[i][j] != -1) return dp[i][j];
        int up=INT_MAX;
        int left=INT_MAX;
        if(i>0)up=grid[i][j]+fn(i-1,j,n,m,grid,dp);
        if(j>0)left=grid[i][j]+fn(i,j-1,n,m,grid,dp);
        dp[i][j]=min(up,left);
        return dp[i][j];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int i=n-1;
        int j=m-1;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        //fn(i,j)=> i,j se 0,0 tak min path sum
        return fn(i,j,n,m,grid,dp);
    }
};