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
    string sol(TreeNode* root, map<string, int>& m, vector<TreeNode*>& ans)
    {
        if(root == NULL)
        {
            return "";
        }

        string s = "(" + sol(root -> left, m, ans) + to_string(root -> val) + 
                    sol(root -> right, m, ans) + ")";
        m[s]++;
        if(m[s] == 2)
        {
            ans.push_back(root);
        }
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string, int> m;
        vector<TreeNode*> ans;
        sol(root, m, ans);
        return ans;
    }
};