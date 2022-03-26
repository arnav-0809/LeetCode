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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        queue<pair<TreeNode*,int>>q;
        map<int,vector<int>>m;
        q.push({root,0});
        while(!q.empty()){
            pair<TreeNode*,int>p=q.front();
            TreeNode*f=p.first;
            int l=p.second;
            m[l].push_back(f->val);
            q.pop();
            if(f->left){
                q.push({f->left,l+1});
            }
            
            if(f->right){
                q.push({f->right,l+1});
            }                  
        }
        
        for(auto &it:m){
            vector<int>v=it.second;
            if(it.first%2)
                reverse(v.begin(),v.end());
            ans.push_back(v);
        }
        return ans;
    }
};