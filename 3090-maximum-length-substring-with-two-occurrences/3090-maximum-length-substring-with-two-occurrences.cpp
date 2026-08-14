class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0;
        int r=0;
        int n=s.size();
        int ans=0;
        unordered_map<char,int> mp;
        while(r <= n-1){
            mp[s[r]]++;

            //invalid window
            while(mp[s[r]] > 2){
                //make window valid
                mp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};