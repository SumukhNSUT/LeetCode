class Solution {
    int fn(int idx, int target, vector<int>&coins, vector<vector<int>>&dp){
        //base case
        if(idx==0){
            if(target%coins[0] == 0) return 1;
            else return 0;
        }
        //general case
        if(dp[idx][target] != -1) return dp[idx][target];
        int pick=0;
        if(coins[idx] <= target){
            pick=fn(idx, target-coins[idx], coins, dp);
        }
        int npick=fn(idx-1,target,coins,dp);
        dp[idx][target]=pick+npick;
        return dp[idx][target];
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        //fn(idx)=> idx se 0 tak
        //dp[idx][target]
        vector<vector<int>>dp(n, vector<int>(amount+1,-1));
        return fn(n-1,amount,coins,dp);
    }
};