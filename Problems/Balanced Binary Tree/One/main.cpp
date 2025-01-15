class Solution {
    pair<int, int> dfs(TreeNode *root) {
        if (root == nullptr) {
            return {0, true};
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        bool isBalance = abs(left.first - right.first) <= 1
            && left.second && right.second;
        return {1 + max(left.first, right.first), isBalance};
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).second;
    }
};
