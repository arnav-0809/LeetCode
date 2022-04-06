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
    TreeNode*sol(vector<int>&p,int&c,int bound){
        if(c==p.size() || p[c]>bound)
            return NULL;
        TreeNode*root=new TreeNode(p[c]);
        c++;
        root->left=sol(p,c,root->val);
        root->right=sol(p,c,bound);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& p) {
        int c=0;
        return sol(p,c,INT_MAX);
    }
};