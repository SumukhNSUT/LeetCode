/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void in(TreeNode* root, unordered_map<int,int>&mp){
        if(root==NULL) return;
        in(root->left, mp);
        //main kaam
        int sum=0; //substree ka sum
        fn(root,sum);
        mp[sum]++;
        in(root->right, mp);
    }
    void fn(TreeNode* root, int &sum){
        if(root==NULL) return;
        fn(root->left,sum);
        sum+=root->val;
        fn(root->right,sum);
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mp;
        in(root,mp);
        vector<int> ans;
        int f=0;
        for(auto it: mp){
            f=max(f,it.second);
        }
        for(auto it: mp){
            if(it.second == f) ans.push_back(it.first);
        }
        return ans;
    }
};