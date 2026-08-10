class Solution {
    int fn(int idx, int target, vector<int>&coins, int n, 
    vector<vector<int>>&dp){
        //base case
        if(idx==0){
            //0 se 0 tak
            if(target % coins[0] == 0) return target/coins[0];
            else return 1e9;
        }

        //general case
        if(dp[idx][target] != -1) return dp[idx][target];
        int npick=0+fn(idx-1,target,coins,n,dp);
        int pick=1e9;
        if(coins[idx] <= target){
            pick=1+fn(idx,target-coins[idx],coins,n,dp);
        }
        dp[idx][target]=min(pick,npick);
        return dp[idx][target];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        //fn(idx,target)=> idx se 0 tak min coins to form target
        int n=coins.size();
        int target=amount;
        //dp[idx][target]
        //idx from 0 to n-1 and target from 0 to target
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        int ans=fn(n-1,target,coins,n,dp);

        if(ans != 1e9) return ans;
        return -1;
    }
};