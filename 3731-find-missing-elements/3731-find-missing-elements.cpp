class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int l=nums[0];
        int r=nums[0];
        int n=nums.size();
        unordered_set<int> s;
        for(auto it: nums){
            l=min(l,it);
            r=max(r,it);
            s.insert(it);
        }
        vector<int>ans;
        for(int i=l; i<=r; i++){
            if(!s.count(i)) ans.push_back(i);
        }
        return ans;
    }
};