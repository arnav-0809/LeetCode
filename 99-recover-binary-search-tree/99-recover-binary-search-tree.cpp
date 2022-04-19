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
    TreeNode*f,*s,*p=new TreeNode(INT_MIN);
    void sol(TreeNode*root){
        if(root==NULL)
            return;
        sol(root->left);
        if(f==NULL && root->val<p->val)
            f=p;
        if(f!=NULL && root->val<p->val)
            s=root;
        p=root;
        sol(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        sol(root);
        swap(f->val,s->val);
    }
};