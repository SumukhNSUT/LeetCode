class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        const int MOD=1e9+7;
        long long h=0, m=0;
        long long ans=0;

        for(int x: nums){
            if(x < a) ans+= m+h;
            else if(x <= b){
                ans += h;
                m++;
            }else h++;
        }
        return ans%MOD;
    }
};