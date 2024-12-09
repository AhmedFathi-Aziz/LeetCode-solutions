class Solution {
public:
    bool dfs(TreeNode *root, int target) {
        if (!root)
            return false;
        target -= root->val;
        if (!root->left && !root->right)
            return target == 0;
        return dfs(root->left, target) ||
               dfs(root->right, target);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum);
    }
};
