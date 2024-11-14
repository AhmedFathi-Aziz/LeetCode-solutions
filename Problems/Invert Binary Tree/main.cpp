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
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node = nullptr;
        TreeNode* temp = nullptr;
        while (!q.empty()) {
            node = q.front();
            q.pop();
            if (!node)
                continue;
            q.push(node->left);
            q.push(node->right);

            temp = node->left;
            node->left = node->right;
            node->right = temp;
        }
        return root;
    }
};
