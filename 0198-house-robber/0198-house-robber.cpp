class Solution {
private:
    int fn(int idx, vector<int>&nums, vector<int>&dp){
        if(idx==0) return nums[0];
        if(idx==1) return max(nums[0],nums[1]);

        if(dp[idx] != -1) return dp[idx];

        int npick=-1e9;
        int pick=-1e9;
        if(idx >= 1) npick=fn(idx-1,nums,dp);
        if(idx >= 2) pick=nums[idx]+fn(idx-2,nums,dp);
        dp[idx]= max(pick,npick);
        return dp[idx];
    }
public:
    int rob(vector<int>& nums) {
        //n-1 se 0 pe jaaunga and max sum return karna hai
        int n=nums.size();
        vector<int> dp(n,-1);
        return fn(n-1,nums,dp);
    }
};