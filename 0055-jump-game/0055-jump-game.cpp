class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int mx=0; //max reachable
        for(int i=0; i<n; i++){
            if(i<=mx){
                int nidx=i+nums[i];
                mx=max(mx,nidx);
                if(nidx >= n-1) return true;
            }else{
                return false;
            }
        }
        return false;
    }
};