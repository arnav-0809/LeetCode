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
class BSTIterator {
    queue<int>ans;
    void sol(TreeNode*r,queue<int>&ans){
        if(r==NULL)
            return;
        sol(r->left,ans);
        ans.push(r->val);
        sol(r->right,ans);
        
    }
public:
    BSTIterator(TreeNode* root) {
        sol(root,ans);
    }
    
    int next() {
        int f=ans.front();
        ans.pop();
        return f;
    }
    
    bool hasNext() {
        if(!ans.empty())
            return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */