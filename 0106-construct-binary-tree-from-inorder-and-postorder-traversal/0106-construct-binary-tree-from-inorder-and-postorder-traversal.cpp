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
    TreeNode* sol(int inS, int inE, int postS, int postE, vector<int>& in, vector<int>& post, map<int, int>& m)
    {
        if(inS > inE || postS > postE)
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(post[postE]);
        int f = m[root -> val];
        int d = f - inS;
        root -> left = sol(inS, f - 1, postS, postS + d - 1, in, post, m);
        root -> right = sol(f + 1, inE, postS + d, postE - 1, in, post, m);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int>m;
        int inS = 0, inE = inorder.size() - 1, postS = 0, postE = postorder.size() - 1;
        for(int i = 0; i <= inE; i++)
        {
            m[inorder[i]] = i;
        }
        return sol(inS, inE, postS, postE, inorder, postorder, m);
    }
};