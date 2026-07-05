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
    void in(TreeNode*root,int maxi, int mini, int&ans){
        if(root==NULL) return;
        maxi=max(maxi,root->val);
        mini=min(mini,root->val);
        ans=max(ans,abs(maxi-mini));
        in(root->left,maxi,mini,ans);
        in(root->right,maxi,mini,ans);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int ans=INT_MIN;
        in(root,maxi,mini,ans);
        return ans;
    }
};