class Solution {
    // //memo
    // int fn(int idx, int target, vector<int>&coins, vector<vector<int>>&dp){
    //     //base case
    //     if(idx==0){
    //         if(target%coins[0] == 0) return 1;
    //         else return 0;
    //     }
    //     //general case
    //     if(dp[idx][target] != -1) return dp[idx][target];
    //     int pick=0;
    //     if(coins[idx] <= target){
    //         pick=fn(idx, target-coins[idx], coins, dp);
    //     }
    //     int npick=fn(idx-1,target,coins,dp);
    //     dp[idx][target]=pick+npick;
    //     return dp[idx][target];
    // }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        //fn(idx)=> idx se 0 tak
        //dp[idx][target]
        vector<vector<int>>dp(n, vector<int>(amount+1,-1));
        //tabulation
        //base case
        for(int target=0; target<=amount; target++){
            if(target%coins[0] == 0){
                dp[0][target]=1;
            }else{
                dp[0][target]=0;
            }
        }
        //general case
        for(int idx=1; idx<=n-1; idx++){
            for(int target=0; target<=amount; target++){
                unsigned int pick=0;
                if(coins[idx] <= target){
                    pick=dp[idx][target-coins[idx]];
                }
                unsigned int npick=dp[idx-1][target];
                dp[idx][target]=pick+npick;
            }
        }
        return dp[n-1][amount];
    }
};