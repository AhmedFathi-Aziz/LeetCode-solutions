class Solution {
public:
    vector<int> sofar;
    vector<vector<int>> output;
    void dfs(TreeNode *root, int target) {
        if (!root)
            return;
        target -= root->val;
        sofar.push_back(root->val);

        if (!root->left && !root->right && !target)
            output.push_back(sofar);
            
        dfs(root->left, target);
        dfs(root->right, target);
        sofar.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return output;
    }
};
