class Solution {
    bool doWork(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr)
            return false;
        if (left->val != right->val)
            return false;
        return doWork(left->left, right->right)
            && doWork(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return doWork(root->left, root->right);
    }
};
