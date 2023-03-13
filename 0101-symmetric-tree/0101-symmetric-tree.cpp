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
public:
    bool sol(TreeNode* l, TreeNode* r)
    {
        if(!l || !r)
        {
            return l == r;
        }
        return l -> val == r -> val && sol(l -> right, r -> left) && sol(l -> left, r -> right);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root)
        {
            return true;
        }
        return sol(root -> left, root -> right);
    }
};