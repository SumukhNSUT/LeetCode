class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int>valid(n,1);
        for(int i=0; i<=n-1; i++){
            int s=intervals[i][0];
            int e=intervals[i][1];
            for(int j=0; j<=n-1; j++){
                if(j!=i){
                    int l=intervals[j][0];
                    int r=intervals[j][1];
                    if(s<=l && e>=r){
                        //jth interval got covered
                        valid[j]=0;
                    }
                }
            }
        }
        int cnt=0;
        for(auto it: valid){
            if(it==1) cnt++;
        }
        return cnt;
    }
};