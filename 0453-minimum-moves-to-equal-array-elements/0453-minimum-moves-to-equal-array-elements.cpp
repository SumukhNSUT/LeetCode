class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini=nums[0];
        for(auto it: nums) mini=min(mini, it);

        int n=nums.size();
        int ans=0;
        for(int i=0; i<n; i++){
            ans+=abs(nums[i]-mini);
        }
        return ans;
    }
};

// Incrementing n-1 elements by 1 is equivalent to decrementing one element by 1 (since subtracting 1 from every element doesn't affect equality).

// So, optimally, reduce every element to the minimum element.