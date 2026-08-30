class Solution {
private:
    int fn(int idx, vector<int>&dp){
        //idx se 0 pe aane ke steps
        if(idx==0) return 1;
        if(idx==1) return 1;
        if(idx==2) return 2;

        if(dp[idx] != -1) return dp[idx];
        int one=fn(idx-1,dp);
        int two=fn(idx-2,dp);
        dp[idx]=one+two;
        return dp[idx];
    }
public:
    int climbStairs(int n) {
        //n se 0 pe aa rha hu
        vector<int> dp(n+1,-1);
        return fn(n,dp);
    }
};