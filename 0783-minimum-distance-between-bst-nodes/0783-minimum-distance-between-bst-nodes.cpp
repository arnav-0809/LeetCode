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
    void sol(TreeNode* root, vector<int>& nodes){
        if(root == NULL){
            return;
        }

        sol(root -> left, nodes);
        nodes.push_back(root -> val);
        sol(root -> right, nodes);
    }
    
    int minDiffInBST(TreeNode* root) {
        vector<int> nodes;
        sol(root, nodes);
        int n = nodes.size(), mini = INT_MAX;;
        for(int i = 1; i < n; i++){
            mini = min(mini, abs(nodes[i] - nodes[i-1]));
        }
        return mini;
    }
};