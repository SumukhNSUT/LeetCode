class Solution {
    bool fn(int idx, vector<int>&nums, int target, int n,
    vector<vector<int>>&dp){
        //n=> size of nums
        if(target==0) return true;
        if(idx==0) return nums[0]==target;

        //general idx
        if(dp[idx][target] != -1) return dp[idx][target];
        bool npick=fn(idx-1,nums,target,n,dp);
        bool pick=false;
        if(nums[idx] <= target){
            pick=fn(idx-1,nums,target-nums[idx],n,dp);
        }
        dp[idx][target]=pick|npick;
        return dp[idx][target];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it: nums) sum+=it;
        if(sum%2 != 0) return false; //odd sum

        //fn(idx)=> idx se 0 tak
        int n=nums.size();
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return fn(n-1,nums,target,n,dp);
    }
};