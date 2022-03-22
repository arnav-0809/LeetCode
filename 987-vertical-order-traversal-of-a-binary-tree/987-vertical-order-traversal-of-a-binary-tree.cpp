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
    static bool comp(pair<int,int> a,pair<int,int> b){
        if(a.second==b.second){
            if(a.first<b.first)
                return true;
        }else if(a.second<b.second){
            return true;
        }
        return false;
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,vector<pair<int,int>>>m;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode*node=it.first;
            pair<int,int> line=it.second;
            if(m.find(line.first)==m.end()){
                vector<pair<int,int>>ans1;
                ans1.push_back({node->val,line.second});
                m[line.first]=ans1;
            }else{
                vector<pair<int,int>>ans1=m[line.first];
                ans1.push_back({node->val,line.second});
                m[line.first]=ans1;
            }
            
            if(node->left!=NULL){
                q.push({node->left,{line.first-1,line.second+1}});
            }
            
            if(node->right!=NULL){
                q.push({node->right,{line.first+1,line.second+1}});
            }
        }
        
        for(auto it:m){
            vector<int>ans1;
            sort(it.second.begin(),it.second.end(),comp);
            for(auto e:it.second){
                ans1.push_back(e.first);
            }
            ans.push_back(ans1);
        }
        return ans;
    }
};