class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int j=n-1;
        vector<int> ans(n);
        int s=0; int e=n-1;
        while(s<=e){
            int x=nums[s]*nums[s];
            int y=nums[e]*nums[e];
            if(x <= y){
                ans[j]=y;
                j--;
                e--;
            }else{
                ans[j]=x;
                j--;
                s++;
            }
        }
        return ans;
    }
};