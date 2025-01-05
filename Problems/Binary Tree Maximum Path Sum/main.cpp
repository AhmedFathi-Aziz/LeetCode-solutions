class Solution {
    int answer = INT_MIN;
    int dfs(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        } 
        int left = dfs(root->left);
        int right = dfs(root->right);
        answer = max(answer, root->val + left + right);
        return max(0, root->val + max(left, right));
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return answer;
    }
};
