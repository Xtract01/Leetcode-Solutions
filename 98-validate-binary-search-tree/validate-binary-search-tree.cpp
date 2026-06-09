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
    bool isValidateBST(TreeNode* root , long minVal , long maxVal){
        if(!root) return true;
        if(root->val>=maxVal || root->val <=minVal) return false;
        return isValidateBST(root->left,minVal,root->val) && isValidateBST(root->right,root->val,maxVal);
    }
    bool isValidBST(TreeNode* root) {
        return isValidateBST(root,LLONG_MIN, LLONG_MAX);
    }
};