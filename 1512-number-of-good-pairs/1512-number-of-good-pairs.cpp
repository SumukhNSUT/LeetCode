class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int n=nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        int ans=0;
        for(auto it: mp){
            int len=it.second.size();
            ans += (len*(len-1))/2;
        }
        return ans;
    }
};