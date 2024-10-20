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
    using ll = long long;
    bool valid(TreeNode *node, ll left, ll right) {
        if (!node)
            return true;
        if (!(node->val > left && node->val < right))
            return false;
        
        return valid(node->left, left, node->val) &&
        valid(node->right, node->val, right);
    }
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, -1e10, 1e10);
    }
};
