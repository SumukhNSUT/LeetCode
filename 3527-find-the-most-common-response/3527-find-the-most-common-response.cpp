class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        vector<vector<string>>ans;
        for(auto it: responses){
            unordered_set<string> st;
            for(int i=0; i<it.size(); i++){
                st.insert(it[i]);
            }
            vector<string> temp;
            for(auto it: st){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        unordered_map<string,int> mp;
        for(auto it: ans){
            for(int i=0; i<it.size(); i++){
                mp[it[i]]++;
            }
        }
        int mx=INT_MIN;
        for(auto it: mp){
            mx=max(mx,it.second);
        }
        vector<string> arr;
        for(auto it: mp){
            if(it.second == mx){
                arr.push_back(it.first);
            }
        }
        sort(arr.begin(),arr.end());
        return arr[0];
    }
};