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
    stack<TreeNode*>ans;
    void sol(TreeNode*r){
        if(r==NULL)
            return;
        ans.push(r);
        sol(r->left);
    }
public:
    BSTIterator(TreeNode* root) {
        sol(root);
    }
    
    int next() {
         TreeNode*f=ans.top();
        ans.pop();
        sol(f->right);
        return f->val;
    }
    
    bool hasNext() {
        return !ans.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */