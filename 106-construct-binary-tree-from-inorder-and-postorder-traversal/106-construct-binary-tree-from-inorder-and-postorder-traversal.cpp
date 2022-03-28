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
    TreeNode*sol(vector<int>&in,int inS,int inE,vector<int>&po,int poS,int poE,map<int,int>&m){
        if(inS>inE || poS>poE)
            return NULL;
        TreeNode*root=new TreeNode(po[poE]);
        int f=m[root->val];
        int d=f-inS;
        root->left=sol(in,inS,f-1,po,poS,poS+d-1,m);
        root->right=sol(in,f+1,inE,po,poS+d,poE-1,m);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        int inS=0,inE=in.size()-1,poS=0,poE=po.size()-1;
        map<int,int>m;
        for(int i=0;i<in.size();i++){
            m[in[i]]=i;
        }
        return sol(in,inS,inE,po,poS,poE,m);
    }
};