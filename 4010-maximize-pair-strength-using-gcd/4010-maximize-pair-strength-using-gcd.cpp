class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n=nums.size();
        long long ans=INT_MIN;
        for(int i=0; i<=n-1; i++){
            for(int j=i+1; j<=n-1; j++){
                long long g=gcd(nums[i],nums[j]);
                long long a= (long long) nums[i]/g;
                long long b=(long long) nums[j]/g;

                ans=max(ans, (a*b));
            }
        }
        return ans;
    }
};