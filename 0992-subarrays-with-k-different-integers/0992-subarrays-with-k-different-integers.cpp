class Solution {
    int fn(vector<int>nums, int k){
        // distinct integers <= k
        int n = nums.size();
        int l =0;
        int r = 0;
        int cnt = 0;
        unordered_map<int,int> mp;
        while(l<=r && r<=n-1){
            mp[nums[r]]++;

            while(mp.size() > k){
                // shrink the window
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            // when valid window
            if(mp.size()<=k){
                cnt+=r-l+1;
            }
            r++;
        }
        return cnt;

    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fn(nums,k)-fn(nums,k-1);    
    }
};