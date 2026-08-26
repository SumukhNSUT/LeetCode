class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 1;
        int last = nums[0];
        int n=nums.size();
        for(int i=1; i<n; i++){
            if(nums[i] != last){
                nums[idx]=nums[i];
                last=nums[idx];
                
                idx++;
            }
        }
        return idx;
    }
};