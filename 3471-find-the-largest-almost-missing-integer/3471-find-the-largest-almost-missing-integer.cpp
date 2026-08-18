class Solution {
private:
    bool fn(int s, int e, vector<int>&nums, int x){
        for(int i=s; i<=e; i++){
            if(nums[i] == x) return true;
        }
        return false;
    }
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0; i<n; i++){
            int x=nums[i];
            //check all windows of size k
            int cnt=0;
            int s=0;
            int e=k-1;
            while(e <= n-1){
                if(fn(s,e,nums,x)){
                    cnt++;
                }
                s++;
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