class Solution {
    // int fn(int idx, int target, vector<int>&coins, int n, 
    // vector<vector<int>>&dp){
    //     //base case
    //     if(idx==0){
    //         //0 se 0 tak
    //         if(target % coins[0] == 0) return target/coins[0];
    //         else return 1e9;
    //     }

    //     //general case
    //     if(dp[idx][target] != -1) return dp[idx][target];
    //     int npick=0+fn(idx-1,target,coins,n,dp);
    //     int pick=1e9;
    //     if(coins[idx] <= target){
    //         pick=1+fn(idx,target-coins[idx],coins,n,dp);
    //     }
    //     dp[idx][target]=min(pick,npick);
    //     return dp[idx][target];
    // }
public:
    int coinChange(vector<int>& coins, int amount) {
        //fn(idx,target)=> idx se 0 tak min coins to form target
        int n=coins.size();
        int target=amount;
        //dp[idx][target]
        //idx from 0 to n-1 and target from 0 to target
        vector<vector<int>>dp(n,vector<int>(target+1,1e9));

        //base case
        for(int t=0; t<=target; t++){
            if(t%coins[0]==0) dp[0][t]=t/coins[0];
            else dp[0][t]=1e9;
        }
        //nested loops
        //idx=0 already done in base case and 'idx-1' should exist
        for(int idx=1; idx<=n-1; idx++){
            for(int t=0; t<=target; t++){
                int npick=0+dp[idx-1][t];
                int pick=1e9;
                if(coins[idx] <= t){
                    pick=1+dp[idx][t-coins[idx]];
                }
                dp[idx][t]=min(pick,npick);
            }
        }
        int ans=dp[n-1][target];
        if(ans != 1e9) return ans;
        return -1;
    }
};