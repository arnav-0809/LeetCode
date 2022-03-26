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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return true;
        else if(p==NULL || q==NULL)
            return false;
        queue<TreeNode*>q1,q2;
        vector<int>v1,v2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty()){
            TreeNode*f=q1.front();
            v1.push_back(f->val);
            if(f->left)
                q1.push(f->left);
            else if(f->right)
                v1.push_back(-1);
            
            if(f->right)
                q1.push(f->right);
            q1.pop();
        }
        
        while(!q2.empty()){
            TreeNode*f=q2.front();
            v2.push_back(f->val);
            if(f->left)
                q2.push(f->left);
            else if(f->right)
                v2.push_back(-1);
            
            if(f->right)
                q2.push(f->right);
            q2.pop();
        }
        if(v1==v2)
            return true;
        return false;
    }
};