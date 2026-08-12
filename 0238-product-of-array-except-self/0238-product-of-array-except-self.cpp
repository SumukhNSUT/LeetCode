class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> suf(n);
        int i=n-1;
        int p=1;
        while(i >= 0){
            suf[i]=p;
            p*=nums[i];
            i--;
        }
        p=1;
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            ans[i]=suf[i]*p;
            p=p*nums[i];
        }
        return ans;
    }
};