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
    TreeNode* prev;
    void sol(TreeNode* root, int& mini){
        if(root == NULL){
            return;
        }

        sol(root -> left, mini);
        if(prev != NULL){
            mini = min(mini, abs(root -> val - prev -> val));
        }
        prev = root;
        sol(root -> right, mini);
    }
    
    int minDiffInBST(TreeNode* root) {
        vector<int> nodes;
        int mini = INT_MAX;
        sol(root, mini);
        return mini;
    }
};