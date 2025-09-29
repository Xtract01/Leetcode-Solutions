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
    vector<int>nodes;
    void helper(TreeNode* root){
        if(root == NULL) return ;
        helper(root->left);
        nodes.push_back(root->val);
        helper(root->right);

    }
    bool isValidBST(TreeNode* root) {
        helper(root);
        for(int i = 1; i < nodes.size(); i++){
            if(nodes[i] <= nodes[i-1]) return false; 
        }
        return true;
    }
};