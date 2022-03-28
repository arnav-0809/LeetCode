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
    TreeNode*prev=NULL;
public:
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode*f=s.top();
            s.pop();
            if(f->right)
                s.push(f->right);
            if(f->left)
                s.push(f->left);
            if(!s.empty())
                f->right=s.top();
            f->left=NULL;
        }
    }
};