class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string str;
        for(auto it: words){
            char ch=it[0];
            str+=ch;
        }

        return str==s;
    }
};