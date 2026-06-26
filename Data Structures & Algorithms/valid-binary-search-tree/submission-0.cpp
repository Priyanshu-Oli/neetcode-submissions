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
    bool isValidBST(TreeNode* root) {
        return validity(root, LONG_MIN,LONG_MAX);
    }

    bool validity(TreeNode* root, long min, long max){
        if(root ==nullptr) return true;

        if(root->val <=min || root->val >=max){
            return false;
        } 
        return validity(root->left,min,root->val) && validity(root->right, root->val , max);
    }
};
