class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int len=needle.size();
        for(int i=0; i<=n-1-(len-1); i++){
            string str=haystack.substr(i,len);
            if(str==needle) return i;
        }
        return -1;
    }
};