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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_set<int> childSet;
        for(vector<int> &vec : descriptions){
            int root = vec[0];
            int child = vec[1];
            bool isLeft = vec[2];
            if(mp.find(root)==mp.end()){
                mp[root] = new TreeNode(root);
            }
            if(mp.find(child)==mp.end()){
                mp[child] = new TreeNode(child);
            }
            if(isLeft){
                mp[root] -> left = mp[child];
            }
            else mp[root] -> right = mp[child];
            childSet.insert(child);
        }
        for(vector<int> &vec : descriptions){
            int parent = vec[0];
            if(childSet.find(parent)==childSet.end()){
                return mp[parent];
            }
        }
        return NULL;
    }
};