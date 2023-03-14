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
    int sol(TreeNode* root, int ans)
    {
        if(!root)
        {
            return 0;
        }
        
        ans = ans * 10 + root -> val;
        if(!root -> left && !root -> right)
        {
            return ans;
        }

        int l = sol(root -> left, ans);
        int r = sol(root -> right, ans);
        return l + r;
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        return sol(root, ans);
    }
};