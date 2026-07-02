class Solution {
public:
  TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                int& preIndex, int left, int right) {

    if (left > right)
        return NULL;

    TreeNode* root = new TreeNode(preorder[preIndex++]);

    int mid = left;
    while (inorder[mid] != root->val)
        mid++;

    root->left = build(preorder, inorder, preIndex, left, mid - 1);
    root->right = build(preorder, inorder, preIndex, mid + 1, right);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preIndex = 0;
    return build(preorder, inorder, preIndex, 0, inorder.size() - 1);
}
};