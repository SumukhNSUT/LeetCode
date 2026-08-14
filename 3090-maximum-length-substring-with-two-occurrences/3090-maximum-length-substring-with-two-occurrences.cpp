class Solution {
private:
    bool valid(unordered_map<char,int>&mp){
        for(auto it: mp){
            if(it.second > 2) return false;
        }
        return true;
    }
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0; i<n; i++){
            unordered_map<char,int> mp;
            for(int j=i; j<n; j++){
                mp[s[j]]++;
                if(valid(mp)){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};