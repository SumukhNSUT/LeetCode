class Solution {
    int fn(int idx, vector<int>&nums, int n,vector<int>&dp){
        //n-> size of nums
        if(idx >= n) return 0;
        if(idx==n-1) return nums[idx];

        if(dp[idx] != -1) return dp[idx];
        //general idx
        int pick=nums[idx]+fn(idx+2,nums,n,dp); //idx pe khade hoke kya options hai, idx+2 pe jaaunga
        int npick=0+fn(idx+1,nums,n,dp); //idx ko pick nhi kiya hai, ab kya option hai, idx+1 pe jaaunga
        dp[idx]=max(pick,npick);
        return dp[idx];
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        //0 to n-1 jaaunga
        //fn(idx)=> idx se n-1 tak max money
        return fn(0,nums,n,dp);
    }
};