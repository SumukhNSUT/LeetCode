class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
        vector<int>ex=heights;
        sort(ex.begin(), ex.end());
        int cnt=0;
        for(int i=0; i<n; i++){
            if(ex[i] != heights[i]) cnt++;
        }
        return cnt;

        
    }
};