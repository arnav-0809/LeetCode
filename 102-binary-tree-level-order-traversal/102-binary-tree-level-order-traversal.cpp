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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        queue<pair<TreeNode*,int>>q;
        map<int,vector<int>>m;
        q.push({root,0});
        while(!q.empty()){
            pair<TreeNode*,int>s=q.front();
            int level=s.second;
            TreeNode*node=s.first;
            m[level].push_back(node->val);
            q.pop();
            if(node->left)
                q.push({node->left,level+1});
            if(node->right)
                q.push({node->right,level+1});
            
        }
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }
};