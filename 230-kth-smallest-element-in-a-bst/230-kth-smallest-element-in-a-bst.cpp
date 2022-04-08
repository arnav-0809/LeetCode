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
    void sol(TreeNode*root,vector<int>&v){
        if(root==NULL)
            return;
        sol(root->left,v);
        v.push_back(root->val);
        sol(root->right,v);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>v;
        sol(root,v);
        return v[k-1];
    }
};