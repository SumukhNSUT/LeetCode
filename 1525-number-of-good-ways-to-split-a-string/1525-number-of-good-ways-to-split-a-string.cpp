class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> mp;
        for(auto it: s) mp[it]++;
        int n=s.size();
        int cnt=0;
        unordered_map<char,int> pref;
        for(int i=0; i<n; i++){       
            pref[s[i]]++;
            mp[s[i]]--;
            if(mp[s[i]] == 0) mp.erase(s[i]);

            if(pref.size() == mp.size()) cnt++;
        }
        return cnt;
    }
};