// class Solution {
// private:
//     void dfs(int node, vector<int>& vis, vector<vector<int>>& adj,
//              vector<int>& quiet, vector<int>& ans) {
//         vis[node] = 1;
//         // int mini=INT_MAX;
//         for (auto it : adj[node]) {
//             ans[it] = min(ans[it], quiet[it]);
//             dfs(it, vis, adj, quiet, ans);
//         }
//     }

// public:
//     vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
//         int n = quiet.size();
//         vector<vector<int>> adj(n);
//         for (auto it : richer) {
//             int u = it[1]; // u to v edge
//             int v = it[0];
//             adj[u].push_back(v);
//         }
//         vector<int> ans(n, INT_MAX);
//         vector<int> vis(n, 0);
//         for (int i = 0; i < n; i++) {
//             if (!vis[i]) {
//                 dfs(i, vis, adj, quiet, ans);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
private:
    int dfs(int node, vector<vector<int>>& adj,
            vector<int>& quiet, vector<int>& ans) {

        // Already computed
        if (ans[node] != -1)
            return ans[node];

        // Initially, assume this node is the quietest
        ans[node] = node;

        // Check all richer people
        for (int it : adj[node]) {
            int candidate = dfs(it, adj, quiet, ans);

            if (quiet[candidate] < quiet[ans[node]])
                ans[node] = candidate;
        }

        return ans[node];
    }

public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {

        int n = quiet.size();

        // Reverse graph: poorer -> richer
        vector<vector<int>> adj(n);

        for (auto &it : richer) {
            int poorer = it[1];
            int richerPerson = it[0];
            adj[poorer].push_back(richerPerson);
        }

        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++)
            dfs(i, adj, quiet, ans);

        return ans;
    }
};