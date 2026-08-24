class Solution {
public:
    long long countSubstrings(string s, char c) {
        int n=s.size();
        vector<int> v(n); //'i' index se aage kitne c pade hai
        int cnt=0;
        for(int i=n-1; i>=0; i--){
            v[i]=cnt;
            if(s[i] == c){
                cnt++;
            }
        }  
        long long ans=0;
        for(int i=0; i<n; i++){
            if(s[i] == c){
                ans++;
                ans+=v[i];
            }
        }
        return ans;
    }
};