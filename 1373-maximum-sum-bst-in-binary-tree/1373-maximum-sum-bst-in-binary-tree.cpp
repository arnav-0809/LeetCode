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
    struct Node{
        int maxVal=INT_MIN;
        int minVal=INT_MAX;
        int sum=0;
        bool isBst=true;
    };
public:
    Node sol(TreeNode*root,int & maxi){
        if(root==NULL)
            return Node();
        
        auto left = sol(root->left, maxi);
        auto right = sol(root->right, maxi);
        
        Node ans;
        ans.isBst = left.isBst && right.isBst && left.maxVal < root->val && root->val < right.minVal;
        
        if(ans.isBst){
            ans.minVal = min(left.minVal, root->val);
            ans.maxVal = max(right.maxVal, root->val);
            ans.sum = left.sum + right.sum + root->val;
        }
        
        maxi = max(maxi, ans.sum);
        
        return ans;
    }
    
    int maxSumBST(TreeNode* root) {
        int maxi = 0;
        sol(root, maxi);
        return maxi;
    }
};