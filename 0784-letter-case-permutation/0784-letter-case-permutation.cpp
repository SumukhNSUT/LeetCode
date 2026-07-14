class Solution {
    void fn(int idx, string &s, vector<string>&ans){
        int n=s.size();
        if(idx==n){
            ans.push_back(s);
            return;
        }

        if(s[idx]>='a' && s[idx]<='z'){
            fn(idx+1,s,ans); //keep as it is
            //change its case
            //agr s[idx] koi lowercase letter hai toh
            s[idx]=toupper(s[idx]);
            fn(idx+1,s,ans);
            //backtrack, restore s when call returns
            s[idx]=tolower(s[idx]);
        }else if(s[idx]>='A' && s[idx]<='Z'){
            fn(idx+1,s,ans); //keep as it is
            //change its case
            s[idx]=tolower(s[idx]);
            fn(idx+1,s,ans);
            //backtrack, restore s when call returns
            s[idx]=toupper(s[idx]);
        }else{
            //agar s[idx] koi number hai toh
            fn(idx+1,s,ans);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        fn(0,s,ans);
        return ans;
    }
};