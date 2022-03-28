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
    bool sol(TreeNode*l,TreeNode*r){
        if(r==NULL || l==NULL)
            return r==l;
        return l->val==r->val && sol(l->left,r->right) && sol(l->right,r->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return sol(root->left,root->right);
    }
};