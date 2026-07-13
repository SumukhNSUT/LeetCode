class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        st.push(nums[0]);
        for(int i=1; i<=n-1; i++){
            if(nums[i] >= st.top()){
                st.push(nums[i]);
            }
        }
        return st.size();
    }
};