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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode *current = root;
        stk.push(current);
        while (current || !stk.empty()) {
            while (current) {
                stk.push(current);
                current = current->left;
            }
            current = stk.top();
            stk.pop();
            if (--k == 0)
                return current->val;
            current = current->right;
        }
        return true;
    }
};
