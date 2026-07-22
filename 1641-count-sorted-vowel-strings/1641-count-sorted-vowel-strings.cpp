// class Solution {
//     void fn(string temp, int n, vector<char>&vow, int &cnt){
//         //base case
//         if(temp.size() == n){
//             cnt++;
//             return;
//         }
//         //general case
//         for(int i=0; i<=4; i++){
//             if(temp.size()==0 || temp.back() >= vow[i]){
//                 temp.push_back(vow[i]);
//                 fn(temp,n,vow,cnt);
//                 temp.pop_back();
//             }
            
//         }
//     }
// public:
//     int countVowelStrings(int n) {
//         vector<char> vow ={'a','e','i','o','u'};
//         int cnt=0;
//         string temp="";
//         fn(temp,n,vow,cnt);
//         return cnt;
//     }
// };
class Solution {
    int fn(int len, int last, int n, vector<vector<int>>& dp) {
        if (len == n)
            return 1;

        if (dp[len][last] != -1)
            return dp[len][last];

        int ans = 0;

        for (int i = last; i < 5; i++) {
            ans += fn(len + 1, i, n, dp);
        }

        return dp[len][last] = ans;
    }

public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(5, -1));
        return fn(0, 0, n, dp);
    }
};