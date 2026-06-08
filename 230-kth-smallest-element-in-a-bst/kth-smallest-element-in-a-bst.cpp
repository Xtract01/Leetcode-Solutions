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
    int inorder(TreeNode* root, int k, int &cnt) {
        if (root == NULL) return -1;

        int left = inorder(root->left, k, cnt);
        if (left != -1) return left;

        cnt++;
        if (cnt == k) return root->val;

        return inorder(root->right, k, cnt);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return inorder(root, k, cnt);
    }
};