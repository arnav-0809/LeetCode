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
    TreeNode*sol(vector<int>&p,int preS,int preE,vector<int>&in,int inS,int inE,map<int,int>&m){
        if(preS>preE || inS>inE)
            return NULL;
        TreeNode*root=new TreeNode(p[preS]);
        int f=m[root->val];
        int d=f-inS;
        root->left=sol(p,preS+1,preS+d,in,inS,f-1,m);
        root->right=sol(p,preS+d+1,preE,in,f+1,inE,m);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& p, vector<int>& in) {
        int preS=0,preE=p.size()-1,inS=0,inE=in.size()-1;
        map<int,int>m;
        for(int i=0;i<in.size();i++){
            m[in[i]]=i;
        }
        return sol(p,preS,preE,in,inS,inE,m);
    }
};