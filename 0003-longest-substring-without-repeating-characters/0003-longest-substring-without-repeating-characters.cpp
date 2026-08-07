class Solution {
    bool valid(unordered_map<char,int>& mp){
        for(auto it: mp){
            if(it.second > 1) return false;
        }
        return true;
    }
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int n=s.size();
        unordered_map<char,int> mp;
        int ans=0;
        while(r < n && l<n){
            mp[s[r]]++;

            //if valid map
            if(valid(mp)){
                ans=max(ans,r-l+1);
            }else{
                //invalid map, make it valid
                while(!valid(mp) && l<n){
                    if(mp.count(s[l])) mp[s[l]]--;
                    if(mp[s[l]] == 0){
                        mp.erase(s[l]);
                    }
                    l++;
                }
                ans=max(ans,r-l+1);
            }
            r++;
        }

        return ans;
    }
};