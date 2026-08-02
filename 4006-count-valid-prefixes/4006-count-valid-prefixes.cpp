class Solution {
public:
    int countValidPrefixes(string s) {
        int n=s.size();
        int cnt=0;
        int c1=0;
        int c0=0;
        for(int i=0; i<n; i++){
            
            if(s[i] == '0') c0++;
            else c1++;
            
            if(abs(c0-c1) <= 1) cnt++;
            
        }
        return cnt;
    }
};