class Solution {
    void dfs(int node, vector<int>&vis, vector<vector<int>>adj, int&cn, int&ce){
        vis[node]=1;
        cn++; //nodes ka count poore component mein
        ce += adj[node].size(); //edges ka count poore component mein
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,cn,ce);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);
        for(auto it: edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                int ce=0;
                int cn=0;
                dfs(i,vis,adj,cn,ce); 
                ce=ce/2; //2 times count ho jayege
                
                if(ce==((cn)*(cn-1))/2) cnt++;
            }
        }
        return cnt;
    }
};