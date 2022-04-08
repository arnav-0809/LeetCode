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
    void sol(TreeNode*root,int k,int &count,int&ans){
        if(root==NULL)
            return;
        sol(root->left,k,count,ans);
        if(++count==k){
            ans=root->val;
            return;
        }
        sol(root->right,k,count,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans=0,count=0;
        sol(root,k,count,ans);
        return ans;
    }
};