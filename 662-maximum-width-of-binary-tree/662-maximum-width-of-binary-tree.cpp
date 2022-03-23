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

#define ll unsigned long long int

class Solution {
    
    vector<vector<ll>> tree;
    
    void solve(TreeNode* root, ll lvl, ll idx) {
        
        if(root == NULL) return;
        
        if(lvl == tree.size()) tree.push_back({});
        
        tree[lvl].push_back(idx);
        
        solve(root->left,  lvl + 1, 2 * idx);
        solve(root->right, lvl + 1, 2 * idx + 1);
        
    }
    
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        solve(root, 0, 0);
        
        ll ans = 0;
        
        for(auto &v : tree) {
            
            ll cur = v.back() - v[0] + 1;
            
            ans = max(ans, cur);
        }
        
        return ans;
    }
};