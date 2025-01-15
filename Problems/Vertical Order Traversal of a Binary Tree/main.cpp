class Solution {
public:
    struct Buffer {
        TreeNode *node;
        int row;
        int col;
    };
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;
        vector<vector<int>> output;
        queue<Buffer> q;
        q.push({root, 0, 0});
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            mp[current.col].emplace_back(current.node->val, current.row);
            if (current.node->left)
                q.push({current.node->left, current.row + 1, current.col - 1});
            if (current.node->right)
                q.push({current.node->right, current.row + 1, current.col + 1});
        }
        for (auto &[col, vec] : mp) {
            sort(vec.begin(), vec.end(),
            [](const pair<int, int> &a, const pair<int, int> &b) {
                if (a.second == b.second)
                    return a.first < b.first;
                return a.second < b.second;
            });
            vector<int> column;
            for (auto &[val, row] : vec)
                column.push_back(val);
            output.push_back(move(column));
        }
        return output;
    }
};
