class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>ans(nums.size());
        int ans1=0;
        for(int i=0;i<nums.size();i++){
            ans[nums[i]]++;
            if(ans[nums[i]]>1){
                ans1=nums[i];
                break;
            }
        }
        return ans1;
        
    }
};