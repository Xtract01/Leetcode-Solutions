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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        int n = preorder.size();
        for(int i = 1; i< n ;i++){
            TreeNode* curr = root;
            TreeNode* newNode = new TreeNode(preorder[i]);
            while(true){
                if(preorder[i]<curr->val){
                    if(curr->left==NULL){
                        curr->left = newNode;
                        break;
                    }
                    curr=curr->left;
                }
                else {
                    if(curr->right==NULL){
                        curr->right = newNode;
                        break;
                    }
                    curr=curr->right;
                }
            }
        }
        return root;
    }
};