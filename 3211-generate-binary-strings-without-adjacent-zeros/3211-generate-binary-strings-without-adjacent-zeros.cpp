//without backtracking
class Solution {
    void fn(string temp, vector<string>& ans, int n) {
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        // If temp is empty
        if (temp.empty()) {
            fn(temp + '0', ans, n);
            fn(temp + '1', ans, n);
            return;
        }

        // If last is 0, only 1 can be added
        if (temp.back() == '0') {
            fn(temp + '1', ans, n);
            return;
        }

        // If last is 1, both 0 and 1 can be added
        if (temp.back() == '1') {
            fn(temp + '1', ans, n);
            fn(temp + '0', ans, n);
            return;
        }
    }

public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        fn("", ans, n);
        return ans;
    }
};