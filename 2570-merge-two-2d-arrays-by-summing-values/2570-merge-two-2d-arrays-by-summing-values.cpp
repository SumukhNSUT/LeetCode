class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int,int> mp; //id, val
        for(auto it: nums1){
            mp[it[0]]=it[1];
        }
        vector<vector<int>> ans;
        for(int i=0; i<nums2.size(); i++){
            if(mp.count(nums2[i][0])){
                int a=nums2[i][1] + mp[nums2[i][0]];
                ans.push_back({nums2[i][0],a});
                mp.erase(nums2[i][0]);
            }else{
                ans.push_back({nums2[i][0],nums2[i][1]});
            }
        }

        for(auto it: mp){
            ans.push_back({it.first,it.second});
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};