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
    void sol(TreeNode* root, int lvl, int& ans){
        if(root == NULL){
            return;
        }

        ans = max(ans, lvl);
        sol(root -> left, lvl + 1, ans);
        sol(root -> right, lvl + 1, ans);
    }

    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int ans = 0;
        sol(root, 0, ans);
        return ans + 1;
    }
};