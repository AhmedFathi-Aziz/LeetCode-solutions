class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> output;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int length = q.size();
            vector<int> level;
            while (length--) {
                auto node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            output.push_back(level);
        }
        return output;
    }
};
