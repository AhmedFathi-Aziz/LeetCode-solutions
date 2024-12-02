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
public:
    bool get(TreeNode *root, TreeNode *subRoot) {
        if (!root)
            return false;
        if (root->val == subRoot->val) {
            if(dfs(root, subRoot)) {
                return true;
            }
        }
        if (get(root->left, subRoot) || 
            get(root->right, subRoot))
            return true;
        return false;
    }

    bool dfs(TreeNode *root, TreeNode *subRoot) {
        if (!root && !subRoot)
            return true;
        if (!root || !subRoot)
            return false;
        if (root->val != subRoot->val)
            return false;
        if (!dfs(root->left, subRoot->left) ||
            !dfs(root->right, subRoot->right))
            return false;
        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return get(root, subRoot);
    }
};
