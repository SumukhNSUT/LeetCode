class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto it: nums) mp[it]++;

        int cnt=mp.size(); //poore array mein distinct elements
        cout << cnt<<endl;
        int ans=0;
        for(int i=0; i<=n-1; i++){
            unordered_set<int> st;
            for(int j=i; j<=n-1; j++){
                st.insert(nums[j]);
                if(st.size()==cnt) ans++;
            }       
        }
        return ans;
    }
};