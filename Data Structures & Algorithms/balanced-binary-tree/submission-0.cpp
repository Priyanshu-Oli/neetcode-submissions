class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        return abs(l - r) <= 1 &&
               isBalanced(root->left) &&
               isBalanced(root->right);
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1 + max(left, right);
    }
};