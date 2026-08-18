class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0; i<n; i++){
            int x=nums[i];
            //check all windows of size k
            int cnt=0;
            int s=0;
            int e=0;
            unordered_map<int,int> mp; //ele,freq
            while(e <= n-1){
                mp[nums[e]]++;
                if(e-s+1 > k){
                    mp[nums[s]]--;
                    if(mp[nums[s]] == 0){
                        mp.erase(nums[s]);
                    }
                    s++;
                }
                if(e-s+1 == k){
                    if(mp.count(x)) cnt++;
                }
                
                e++;
            }
            
            if(cnt == 1){
                ans=max(ans,x);
            }
        }
        if(ans != INT_MIN) return ans;
        return -1;
    }
};
