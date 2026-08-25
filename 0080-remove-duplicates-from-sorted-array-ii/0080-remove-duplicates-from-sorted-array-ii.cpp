class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        int cnt=0;
        int idx=0;
        for(auto it: mp){
            int a=min(it.second,2);
            cnt+=a;
            //modify array too
            int val=it.first;
            for(int i=1; i<=a; i++){
                nums[idx]=val;
                idx++;
            }
        }
        return cnt;
    }
};