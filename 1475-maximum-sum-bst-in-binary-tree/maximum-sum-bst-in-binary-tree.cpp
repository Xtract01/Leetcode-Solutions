class Info {
public:
    int min, max, sum;
    bool isBST;
    Info(int mi, int ma, int sm, bool bst) {
        min = mi;
        max = ma;
        sum = sm;
        isBST = bst;
    }
};

class Solution {
public:
    int maxSum = 0;

    Info helper(TreeNode* root) {
        if (!root) return Info(INT_MAX, INT_MIN, 0, true);

        Info left = helper(root->left);
        Info right = helper(root->right);

        if (left.isBST && right.isBST && root->val > left.max && root->val < right.min) {
            int currSum = root->val + left.sum + right.sum;
            maxSum = max(maxSum, currSum);
            return Info(min(root->val, left.min), max(root->val, right.max), currSum, true);
        }

        return Info(INT_MIN, INT_MAX, 0, false); // invalid BST
    }

    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};
