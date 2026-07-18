class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string ans="";
        int cntx=0; int cnty=0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == x) cntx++;
            if(s[i]==y) cnty++;
        }
        while(cnty > 0) {
            ans.push_back(y);
            cnty--;
        }
        while(cntx > 0) {
            ans.push_back(x);
            cntx--;
        }
        for(int i=0; i<s.size(); i++){
            if(s[i] != x && s[i] != y) ans.push_back(s[i]);
        }
        return ans;
    }
};