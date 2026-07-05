class Solution {
public:
    int minChanges(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=1; i<=n-1; i++){
            if(i%2 != 0){
            if(s[i]!=s[i-1]) cnt++;}
        }
        return cnt;
    }
};