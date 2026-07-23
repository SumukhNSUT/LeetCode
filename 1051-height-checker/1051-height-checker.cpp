class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
        map<int,int> freq;
        for(auto it: heights) freq[it]++;
        int idx=0;
        int cnt=0;
        for(auto it: freq){
            while(it.second > 0){
                if(heights[idx] != it.first){
                    cnt++;
                }
                it.second--;
                idx++;
            }
        }
        return cnt;
    }
};