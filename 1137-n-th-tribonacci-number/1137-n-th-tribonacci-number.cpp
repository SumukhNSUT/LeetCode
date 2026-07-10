class Solution {
    int fn(int n, vector<int>&dp){
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;

        if(dp[n]!=-1) return dp[n];
        dp[n]=fn(n-3,dp)+fn(n-2,dp)+fn(n-1,dp);
        return dp[n];
    }
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        vector<int>dp(n+1,-1);
        return fn(n,dp);
    }
};