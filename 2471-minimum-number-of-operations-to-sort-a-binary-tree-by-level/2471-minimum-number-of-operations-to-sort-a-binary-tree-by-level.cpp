/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int fn(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> v;

        for(int i = 0; i < n; i++)
            v.push_back({arr[i], i});

        sort(v.begin(), v.end());
        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++)
            adj[i].push_back(v[i].second);

        vector<bool> vis(n, false);

        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;

            queue<int> q;
            q.push(i);
            vis[i] = true;

            int cnt = 0;
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                cnt++;

                for(auto nxt : adj[node]) {
                    if(!vis[nxt]) {
                        vis[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
            if(cnt > 1)
                ans += cnt - 1;
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        if (root)
            q.push(root);

        int cnt = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;
            for (int i = 1; i <= size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);

                temp.push_back(node->val);
            }
            cnt += fn(temp);
            cout << cnt << endl;
        }
        return cnt;
    }
};