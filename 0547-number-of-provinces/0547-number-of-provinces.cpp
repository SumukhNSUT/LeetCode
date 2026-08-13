class Solution {
private:
    void dfs(vector<int> &vis, int node,vector<vector<int>>&adj){
        vis[node]=1;
        //neighbours of node
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(vis,it,adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1){
                    //edge btw i and j
                    adj[i].push_back(j);
                }
            }
        }
        //solve
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(vis,i,adj);
                cnt++;
            }
        }
        return cnt;
    }
};