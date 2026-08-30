class Solution {
private:
    int fn(int idx, vector<int>&arr, vector<int>&dp){
        //idx se 0 tak max money
        if(idx == 0) return arr[0];
        if(idx == 1) return max(arr[0],arr[1]);

        if(dp[idx] != -1) return dp[idx];

        int npick=0+fn(idx-1,arr,dp);
        int pick=arr[idx]+fn(idx-2,arr,dp);
        return dp[idx]=max(pick,npick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> t1;
        for(int i=1; i<=n-1; i++) t1.push_back(nums[i]); //leave first
        vector<int> t2;
        for(int i=0; i<=n-2; i++) t2.push_back(nums[i]); //leave last
        vector<int>dp1(t1.size(),-1);
        vector<int>dp2(t2.size(),-1);
        int ans1=fn(t1.size()-1,t1,dp1);
        int ans2=fn(t2.size()-1,t2,dp2);
        return max(ans1,ans2);
    }
};