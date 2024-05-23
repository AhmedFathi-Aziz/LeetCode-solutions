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
    pair<bool, int> dfs(TreeNode* root) {
        if (!root)
            return {true, 0};
        
        auto right = dfs(root->right);
        if (!right.first)
            return {false, 0};

        auto left = dfs(root->left);
        if (!left.first)
            return {false, 0};

        bool isBalanced = abs(right.second - left.second) <= 1;
        int height = max(right.second, left.second) + 1;

        return {isBalanced, height};
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }
};
