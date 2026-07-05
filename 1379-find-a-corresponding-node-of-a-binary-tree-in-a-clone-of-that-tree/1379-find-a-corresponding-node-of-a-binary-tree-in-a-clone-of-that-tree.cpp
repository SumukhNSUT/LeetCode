class Solution {
    void inorder(TreeNode*original, TreeNode*cloned, TreeNode*target,TreeNode*&ans) {
        if (original==NULL) return;
        inorder(original->left,cloned->left,target,ans);
        if (original==target) {
            ans=cloned;
            return;
        }
        inorder(original->right,cloned->right,target,ans);
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode*ans=NULL;
        inorder(original,cloned,target,ans);
        return ans;
    }
};