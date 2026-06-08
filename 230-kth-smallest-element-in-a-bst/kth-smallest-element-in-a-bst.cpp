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

    void inorder(vector<int> &inOrder, TreeNode* root){
        if(!root) return;
        inorder(inOrder,root->left);
        inOrder.push_back(root->val);
        inorder(inOrder,root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inOrder;
        inorder(inOrder,root);
        return inOrder[k-1];
    }
};