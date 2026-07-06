class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        //sort by start times
        //same start time pe, larger end time wala pehle aayega
        sort(intervals.begin(),intervals.end(),[](auto &a, auto &b){
            if(a[0]==b[0]){
                //same start time, larger end time first
                return a[1]>b[1]; 
            }
            return a[0]<b[0]; //agar yeh expression true hai toh a comes before b
        });
        int n=intervals.size();
        int e=-1; //max end
        int cnt=0;
        for(auto it: intervals){
            if(it[1] <= e){
                cnt++; //remove it
            }
            e=max(e,it[1]);
        }
        return n-cnt;
    }
};