class Solution {
    void fn(int idx, int sum, int n,  vector<int>&nums, int &ans){
        if(idx==n){
            ans+=sum;
            return;
        }
        //pick
        fn(idx+1,sum^nums[idx],n,nums,ans);
        //not pick
        fn(idx+1,sum,n,nums,ans);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int idx=0;
        int ans=0;
        int sum=0;
        fn(idx,sum,n,nums,ans);
        return ans;
    }
};