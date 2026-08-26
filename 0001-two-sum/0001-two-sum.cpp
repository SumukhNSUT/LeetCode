class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> mp; //val,index
        for(int i=0; i<n; i++){
            int a=nums[i];
            if(mp.count(target-a)){
                return {mp[target-a],i};
            }
            mp[a]=i;
        }
        return {};
    }
};