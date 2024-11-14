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
    int diameter = 0;
    int depth(TreeNode *root) {
        if (!root)
            return 0;
        int left = depth(root->left);
        int right = depth(root->right);

        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return diameter;
    }
};

/*
    return the maximum depth of the subtree rooted at the current node
    for each node
        compute the sum of depths of its left and right subtrees
        maximize the answer
*/
