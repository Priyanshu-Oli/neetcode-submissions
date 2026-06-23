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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
     if(subRoot==nullptr){
        return true;
     }   
     if(root == nullptr){
        return false;
     }
     if(isSameTree(root,subRoot)){
        return true;
     }
     return isSubtree(root->left, subRoot)|| isSubtree(root->right, subRoot);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both nodes are null
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // One is null, the other isn't
        if (p == nullptr || q == nullptr) {
            return false;
        }

        // Values don't match
        if (p->val != q->val) {
            return false;
        }

        // Check left and right subtrees
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
