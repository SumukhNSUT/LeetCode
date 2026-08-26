class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l=0;
        int r=0;
        int n=s.size();
        int cnt=0; //cnt of 1's
        string ans="";
        while(r <= n-1){
            if(s[r] == '1'){
                cnt++;
            }
            while(cnt > k){
                //shrink window
                if(s[l] == '1'){
                    cnt--;
                }
                l++;
            }
            //valid window
            if(cnt == k){
                while(s[l] =='0') l++; //leading 0's hata do

                string temp="";
                //l to r substring
                for(int i=l; i<=r; i++){
                    temp+=s[i];
                }
                if(ans=="" || temp.size()<ans.size() || temp.size()==ans.size() && temp<ans){
                    ans=temp;
                }
            }
            r++;
        }
        return ans;
    }
};