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
    Lever Order Traversal
    BFS
 */
class Solution {
public:
    void invert(TreeNode* root) {
        if (!root)
            return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {   
            TreeNode* node = q.front();
            q.pop();
            TreeNode* p = node->left;
            node->left = node->right;
            node->right = p;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right); 
        }
    }
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};
