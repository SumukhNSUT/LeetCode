class Solution {
private:
    int fn(int row, int col, vector<vector<int>>&triangle, vector<vector<int>>&dp){
        int n=triangle.size();
        int m=triangle[0].size();
        if(row > n-1 || col > triangle[row].size()-1) return 1e9; //invalid path
        if(row == n-1) return triangle[n-1][col];

        if(dp[row][col] != 1e9) return dp[row][col];

        int d=triangle[row][col] + fn(row+1,col,triangle,dp);
        int brd=triangle[row][col]+fn(row+1,col+1,triangle,dp);
        return dp[row][col]=min(d,brd);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        //[0,0] se n-1 row pe jaa rha hu
        int m=triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,1e9));
        return fn(0,0,triangle,dp);
    }
};