class Solution {
private:
    int fn(int idx, vector<int>&coins, int target, vector<vector<int>> &dp){
        //base case
        if(idx==0){
            if(target%coins[idx] != 0) return 0;
            else return 1;
        }
        //general case
        if(dp[idx][target] != -1) return dp[idx][target];
        int npick=fn(idx-1,coins,target,dp);
        int pick=0;
        if(coins[idx] <= target){
            pick=fn(idx,coins,target-coins[idx],dp);
        }
        dp[idx][target]= pick+npick;
        return dp[idx][target];
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        return fn(n-1,coins,amount,dp);
    }
};