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
    unordered_set<int>ans;
    bool a=false;
    void sol(TreeNode*root,int k){
        if(root==NULL)
            return;
        sol(root->left,k);
        if(ans.count(k-root->val)){
            a=true;
            return;
        }
        ans.insert(root->val);
        sol(root->right,k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        sol(root,k);
        return a;
    }
};