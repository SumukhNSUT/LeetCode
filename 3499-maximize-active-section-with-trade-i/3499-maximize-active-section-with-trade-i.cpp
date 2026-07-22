class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        vector<int> ans;
        int cnt=0;
        for(int i=0; i<=n-1; i++){
            if(s[i] == '1') cnt++;
            if(s[i]=='0'){
                int start=i;
                int end=i;
                while(i<n && s[i]=='0') {
                    i++;
                    end++;
                }
                if(s[i]=='1') cnt++;
                ans.push_back(end-start);
            }

        }
        if(ans.size() <= 1) return cnt;
        int maxi=0;
        for(int i=0; i<=ans.size()-2; i++){
            maxi=max(maxi,ans[i]+ans[i+1]);
        }
        return maxi+cnt;
    }
};