class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int ans=0;
        int mr=-1; //max range
        vector<pair<int,int>>v;
        for(auto it: nums){
            int maxi=INT_MIN; //max digit
            int mini=INT_MAX; //min digit
            int num=it;
            if(num==0) maxi=mini=0;
            while(num > 0){
                int d=num%10;
                maxi=max(maxi,d);
                mini=min(mini,d);
                num=num/10;
            }
            int r=maxi-mini;
            v.push_back({it,r});
            mr=max(mr, r);
        }
        for(auto it:v){
            if(it.second==mr) ans+=it.first;
        }
        return ans;
    }
};