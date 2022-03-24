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
    void solve(TreeNode*root,int lvl,int &ans){
        if(root==NULL)
            return;
        ans=max(ans,lvl);
        solve(root->left,lvl+1,ans);
        solve(root->right,lvl+1,ans);
    }
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=0;
        solve(root,0,ans);
        return ans+1;
    }
};