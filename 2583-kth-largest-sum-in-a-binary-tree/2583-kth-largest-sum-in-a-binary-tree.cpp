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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long int>ans;
        queue<pair<TreeNode* , int>>q;
        q.push({root, 0});
        while(!q.empty())
        {
            auto f = q.front();
            q.pop();
            TreeNode* node = f.first;
            int lvl = f.second;
            if(lvl == ans.size())
            {
                ans.push_back(node -> val);
            }
            else
            {
                ans[lvl] += node -> val;
            }

            if(node -> left)
            {
                q.push({node -> left, lvl + 1});
            }

            if(node -> right)
            {
                q.push({node -> right, lvl + 1});
            }
        }

        sort(ans.begin(), ans.end(), greater<long long int>());
        int n = ans.size();
        if(k > n)
        {
            return -1;
        }
        else
        {
            return ans[k - 1];
        }
    }
};