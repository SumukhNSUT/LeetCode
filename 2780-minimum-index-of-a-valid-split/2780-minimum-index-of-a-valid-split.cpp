class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it: nums) mp[it]++;
        int ele=-1;
        int n=nums.size();
        int total=-1;
        for(auto it: mp){
            if(it.second > n/2){
                ele=it.first;
                total=it.second;
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            if(nums[i] == ele){
                cnt++;
                //0 to i
                int len=i-0+1;
                int rcnt=total-cnt;
                int rlen=n-len;
                //i+1 to n-1
                if(rcnt > rlen/2 && cnt > len/2){
                    return i;
                }
            }
        }
        return -1;
    }
};