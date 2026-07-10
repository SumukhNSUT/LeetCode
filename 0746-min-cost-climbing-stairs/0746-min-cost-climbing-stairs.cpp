class Solution {
    int fn(int idx, int n, vector<int>&cost, vector<int>&dp){
        //base case
        if(idx==n-1) return cost[idx];
        if(idx==n-2) return cost[idx];

        if(dp[idx] != -1) return dp[idx];
        //for general idx
        int one=cost[idx]+fn(idx+1,n,cost,dp);
        int two=cost[idx]+fn(idx+2,n,cost,dp);
        dp[idx]=min(one,two);
        return dp[idx];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        //0 to n stairs
        //fn(idx)=> idx se n pe jaane ki min cost
        vector<int>dp(n+1,-1);
        return min(fn(1,n,cost,dp),fn(0,n,cost,dp));
    }
};