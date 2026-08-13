class Solution {
private:
    bool dfs(int node, vector<vector<int>>&adj, vector<int>&vis, vector<int>&color){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it] && color[it]==-1){
                color[it]=!color[node];
                if(dfs(it,adj,vis,color) == false) return false;
            }else if(color[it] == color[node]){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size(); //0 to n-1 vertices
        vector<vector<int>>adj=graph;
        vector<int> vis(n,0);
        vector<int> color(n,-1); //0,1 colors

        for(int i=0; i<=n-1; i++){
            if(color[i]==-1 && !vis[i]){
                color[i]=0; //color of start node
                if(dfs(i,adj,vis,color) == false){
                    return false; //not bipartite
                }
            }
        }
        return true;
    }
};