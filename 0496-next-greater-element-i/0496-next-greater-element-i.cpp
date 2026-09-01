class Solution {
private:
    vector<int> fn(vector<int> arr){
        int n=arr.size();
        vector<int> nge(n,-1);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            if(i==n-1){
                st.push(arr[i]);
                continue;
            }

            while(!st.empty() && arr[i]>=st.top()) st.pop();
            if(!st.empty()) nge[i]=st.top();
            st.push(arr[i]);
        }
        return nge;
    }
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge=fn(nums2);
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            int val=nums1[i];
            for(int j=0; j<nums2.size(); j++){
                if(val == nums2[j]){
                    ans.push_back(nge[j]);
                }
            }
        }
        return ans;
    }
};