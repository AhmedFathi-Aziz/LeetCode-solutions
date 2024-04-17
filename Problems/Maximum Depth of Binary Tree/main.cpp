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
    int depth(TreeNode* root) {
        if (!root)
            return 0;
        int res = 0;
        res = max(res, 1 + depth(root->right));
        res = max(res, 1 + depth(root->left));
        return res;
    }
    int maxDepth(TreeNode* root) {
        return depth(root);
    }
};
