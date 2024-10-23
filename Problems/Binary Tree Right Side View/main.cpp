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
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode*> q;
        int len = 0;
        q.push(root);
        TreeNode *node = nullptr;
        vector<int> answer;
        while (!q.empty()) {
            len = q.size(); 
            while (len--) {
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
        return answer;
    }
};
