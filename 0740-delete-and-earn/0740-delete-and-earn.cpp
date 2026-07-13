class Solution {
public:
    int fn(int idx, unordered_map<int,int>& mpp, vector<int>& v,
           vector<int>& dp) {

        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];

        int pick;
        if(idx>=1 && v[idx-1] == v[idx]-1)
            pick = v[idx] * mpp[v[idx]] + fn(idx-2, mpp, v, dp);
        else
            pick = v[idx] * mpp[v[idx]] + fn(idx-1, mpp, v, dp);

        int npick = fn(idx-1, mpp, v, dp);

        return dp[idx] = max(pick, npick);
    }

    int deleteAndEarn(vector<int>& nums) {
        //fn(idx)=> idx se 0 tak max points
        unordered_map<int,int> mpp;
        for(auto x : nums)
            mpp[x]++;

        vector<int> v;
        for(auto it : mpp)
            v.push_back(it.first);

        sort(v.begin(), v.end());

        int n = v.size();
        vector<int> dp(n, -1);

        return fn(n-1, mpp, v, dp);
    }
};