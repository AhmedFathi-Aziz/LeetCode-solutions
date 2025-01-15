class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        queue<TreeNode*> q;
        q.push(root);

        bool flag = false;
        vector<vector<int>> output;
        while (!q.empty()) {
            int n = q.size();
            vector<int> level;
            while (n--) {
                auto node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                level.push_back(node->val);
            }
            if (flag)
                reverse(level.begin(), level.end());
            output.push_back(level);
            flag = !flag;
        }
        return output;
    }
};
