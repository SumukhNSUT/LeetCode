class Solution {
    int fn(int s, int e, vector<int>& nums, vector<vector<int>>&dp) {
        //base case
        if (s==e) return nums[s];

        if(dp[s][e]!=-1) return dp[s][e];
        //pick left
        int left=nums[s]-fn(s+1,e,nums,dp);
        //pick right
        int right = nums[e]-fn(s,e-1,nums,dp);
        dp[s][e]=max(left, right);
        return dp[s][e];
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        //[s,e] tak max score diff >= 0
        //p1 try to maximize score diff

        //dp[s][e]
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return fn(0,n-1,nums,dp) >= 0;
    }
};