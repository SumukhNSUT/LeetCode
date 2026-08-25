class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        map<int,vector<pair<int,int>>> mp; //(i+j) and index
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[i+j].push_back({i,j});
            }
        }

        vector<int> ans;
        int rev=true;
        for(auto it: mp){
            vector<int> temp;
            for(auto it1: it.second){
                int i=it1.first;
                int j=it1.second;
                temp.push_back(mat[i][j]);
                
            }
            if(rev){
                    reverse(temp.begin(),temp.end());
                    for(auto it: temp) ans.push_back(it);
                    rev=false;
                }else{
                    for(auto it: temp) ans.push_back(it);
                    rev=true;
                }
        }
        return ans;
    }
};
