class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>edges=invocations;
        vector<int> in(n);
        vector<vector<int>>adj(n);
        for(auto it: edges){
            int u=it[0];
            int v=it[1]; //u to v edge
            in[v]++;
            adj[u].push_back(v);
        }   
        //all suspicious nodes in sus
        vector<int> sus(n,0);
        queue<int> q;
        q.push(k);
        sus[k]=1;
        vector<int> vis(n);
        vis[k]=1;
        while (!q.empty()) {
            int size=q.size();
            for(int i=1; i<=size; i++){
                int node=q.front();
                q.pop();
                for(auto it: adj[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=1;
                        sus[it]=1;
                    }
                }
            }
        }
        //solve
        vector<int> ans;
        //if any non sus invokes a sus one, then nothing can be removed
        for(auto it: edges){
            int u=it[0];
            int v=it[1]; //u to v edges
            if(sus[u]==0 && sus[v]==1){
                for(int i=0; i<n; i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        //else return non suspicious methods, all sus can be removed
        for(int i=0; i<n; i++){
            if(sus[i] == 0) ans.push_back(i);
        }
        
        return ans;
    }
};