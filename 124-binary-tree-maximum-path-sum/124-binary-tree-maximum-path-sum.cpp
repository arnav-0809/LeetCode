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
    int solve(int &maxi,TreeNode* root){
        if(root==NULL)
            return 0;
        int lsum=max(0,solve(maxi,root->left));
        int rsum=max(0,solve(maxi,root->right));
        maxi=max(lsum+rsum+root->val,maxi);
        return max(lsum,rsum)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        solve(maxi,root);
        return maxi;
    }
};