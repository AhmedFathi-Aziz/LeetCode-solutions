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
    using ll = long long;
    bool dfs(ll left, TreeNode *root, ll right) {
        if (!root)
            return true;
        if (!(left < root->val && root->val < right))
            return false;
        return dfs(root->val, root->right, right) &&
               dfs(left, root->left, root->val);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(-1e10, root, 1e10);
    }
};
