class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int n=s.size();
        string ans="";
        for(int i=0; i<n; i++){
            if(s[i]==')'){
                string temp="";
                while(!st.empty() && st.top() != '('){
                    char ch=st.top();
                    st.pop();
                    temp+=ch;
                }
                if(st.top()=='(') st.pop();
                for(auto it: temp) st.push(it);
            }else{
                //anything except closing bracket
                st.push(s[i]);
            }

        }
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};