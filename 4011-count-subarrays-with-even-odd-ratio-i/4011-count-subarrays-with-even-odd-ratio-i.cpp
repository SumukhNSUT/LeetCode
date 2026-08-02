class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size();
        int cnt=0;
        double target=double (a)/ double(b);
        for(int i=0; i<n; i++){
            int cnte=0;
            int cnto=0;
            for(int j=i; j<n; j++){
                if(nums[j]%2 == 0) cnte++;
                else cnto++;    

                if(cnto != 0){
                    double ratio=(double)cnte/cnto;
                    if(ratio <= target) cnt++;
                }
            }
        }
        return cnt;
    }
};