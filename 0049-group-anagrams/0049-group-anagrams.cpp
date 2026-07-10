class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>v=strs;
        int n=strs.size();
        unordered_map<string,vector<int>>mp; //str,indexes
        for(int i=0; i<=n-1; i++){
            sort(v[i].begin(),v[i].end());
            mp[v[i]].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto it: mp){
            vector<int>idx=it.second; //indexes
            vector<string> temp;
            for(int i=0; i<idx.size(); i++){
                temp.push_back(strs[idx[i]]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};