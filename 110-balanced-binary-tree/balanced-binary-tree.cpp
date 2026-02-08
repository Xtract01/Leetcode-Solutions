class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;
        int leftH = height(root->left);
        int rightH = height(root->right);

        return max(leftH,rightH) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int left = height(root->left);
        int right = height(root->right);
        if(abs(left-right)>1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};