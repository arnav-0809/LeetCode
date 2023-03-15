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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int leftExists = 1, rightExists = 1;
        while(!q.empty())
        {
            auto f = q.front();
            q.pop();
            if(f -> left && rightExists == 0)
            {
                return false;
            }

            if(f -> left)
            {
                q.push(f -> left);
            }
            else
            {
                leftExists = 0;
            }

            if(leftExists == 0 && f -> right)
            {
                return false;
            }

            if(f -> right)
            {
                q.push(f -> right);
            }
            else
            {
                rightExists = 0;
            }
        }

        return true;
    }
};