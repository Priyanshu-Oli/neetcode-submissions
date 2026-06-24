class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // 0 or 1 child
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            // 2 children
            TreeNode* successor = root->right;

            while (successor->left) {
                successor = successor->left;
            }

            root->val = successor->val;

            root->right = deleteNode(root->right, successor->val);
        }

        return root;
    }
};