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
    vector<int> answer;
    void bfs(TreeNode *root) {
        if (root == nullptr)
            return;
        queue<TreeNode*> q;
        q.push(root);

        TreeNode *node = nullptr;
        while (!q.empty()) {
            int length = q.size();
            for (int i = 0; i < length; i++) {
                node = q.front();
                q.pop();
                if (node) {
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                }
            }
            if (node)
                answer.push_back(node->val);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        bfs(root);
        return answer;
    }
};
