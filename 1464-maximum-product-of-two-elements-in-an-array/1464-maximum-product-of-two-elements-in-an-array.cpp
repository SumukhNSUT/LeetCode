class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx1=INT_MIN;
        int mx2=INT_MIN;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(mx1 < nums[i]){
                mx2=mx1;
                mx1=nums[i];
            }else{
                mx2=max(mx2,nums[i]);
            }
        }
        return (mx1-1)*(mx2-1);
    }
};