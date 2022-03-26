/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool path(vector<TreeNode*>&ans,TreeNode*root,TreeNode*p){
        if(root==NULL)
            return false;
        
        ans.push_back(root);
        
        if(root->val==p->val)
            return true;
        
        if(path(ans,root->left,p)||path(ans,root->right,p))
            return true;
            
        ans.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>ans1,ans2;
        bool path1=path(ans1,root,p);
        bool path2=path(ans2,root,q);
        TreeNode*ans;
        map<TreeNode*,int>m;
        if(ans1.size()<ans2.size()){
            
            for(int i=0;i<ans1.size();i++){
                m[ans1[i]]=i;
            }
            
            for(int i=0;i<ans2.size();i++){
                if(m.find(ans2[i])!=m.end()){
                    ans=ans2[i];
                }
            }
            
        }else{
            for(int i=0;i<ans2.size();i++){
                m[ans2[i]]=i;
            }
            
            for(int i=0;i<ans1.size();i++){
                if(m.find(ans1[i])!=m.end()){
                    ans=ans1[i];
                }
            }
        }
        return ans;
    }
};