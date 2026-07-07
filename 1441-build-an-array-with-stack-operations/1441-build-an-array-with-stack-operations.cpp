class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int idx=0;
        vector<string>ans;
        int s=target.size();
        for(int i=1; i<=n; i++){
            if(idx==s) break;
            if(idx<=s-1 && target[idx]==i){
                ans.push_back("Push");
                idx++;
            }else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};