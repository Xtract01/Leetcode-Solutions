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
    int sumNodes(TreeNode* root) {
        if (!root) return 0;

        int sumLeft = sumNodes(root->left);
        int sumRight = sumNodes(root->right);

        return sumLeft + sumRight + root->val;
    }
    int countNodes(TreeNode* root){
        if(!root) return 0;

        int cntLeft = countNodes(root->left);
        int cntRight = countNodes(root->right);

        return cntLeft+cntRight+1;
    }
    int averageOfSubtree(TreeNode* root) {
        if (!root) return 0;

        int sum = sumNodes(root);
        int count = countNodes(root);

        int ans = 0;

        if (root->val == sum / count) {
            ans++;
        }
        ans += averageOfSubtree(root->left);
        ans += averageOfSubtree(root->right);
        return ans;
    }
};