class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> orig=arr;
        unordered_set<int> st;
        for(auto it: arr) st.insert(it);
        int r=st.size(); //max rank
        unordered_map<int,int>mp;
        vector<int> v;
        for(auto it: st) v.push_back(it);
        sort(v.begin(), v.end());
        int n=v.size();
        int idx=n-1;
        while(idx >= 0){
            mp[v[idx]]=r;
            idx--;
            r--;
        }
        vector<int> ans;
        for(int i=0; i<orig.size(); i++){
            ans.push_back(mp[orig[i]]);
        }
        return ans;
    }
};