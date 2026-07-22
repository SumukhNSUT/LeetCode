class Solution {
    int fn(int idx, vector<int>&nums, int target, int n){
        //base case
        if(idx==0){
            //0 se 0 tak
            int cnt=0;
            if(target==nums[0]) cnt++; //assign +ve to nums[0]
            if(target==-nums[0]) cnt++; //assign -ve to nums[0]
            return cnt;
        }

        //general case
        int plus=fn(idx-1,nums,target-nums[idx],n);
        int minus=fn(idx-1,nums,target+nums[idx],n);
        return plus+minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        //fn(idx)=> idx se 0 tak jaa rha hu
        return fn(n-1,nums,target,n);
    }
};