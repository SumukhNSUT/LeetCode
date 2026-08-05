class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l=0;
        int r=0;
        int n=nums.size();
        int ans=0;
        priority_queue<pair<int,int>> mx;
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > mn;
        //solve
        while(r <= n-1){
            mx.push({nums[r],r});
            mn.push({nums[r],r});

            //l to r window ke elements hone chahiye bas dono heaps mein
            while(!mn.empty() && mn.top().second < l){
                mn.pop();
            }
            while(!mn.empty() && mx.top().second < l){
                mx.pop();
            }
            
            //shrink until valid window
            while(mx.top().first-mn.top().first > limit){
                l++;
                //l to r window ke elements hone chahiye bas dono heaps mein
                while(!mn.empty() && mn.top().second < l){
                    mn.pop();
                }
                while(!mn.empty() && mx.top().second < l){
                    mx.pop();
                }
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};