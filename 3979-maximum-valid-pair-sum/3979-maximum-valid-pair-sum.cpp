class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=k;
        int mi=nums[i]; //i pe max
        int ans=INT_MIN;
        while (j<=n-1) {
            mi=max(mi, nums[i]);
            ans=max(ans,mi+nums[j]);
            i++;
            j++;
        }
        return ans;
    }
};