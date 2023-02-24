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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root == NULL)
        {
            return v;
        }

        queue<pair<TreeNode* ,int>> q;
        q.push({root, 0});

        while(!q.empty())
        {
            auto f = q.front();
            q.pop();
            int lvl = f.second;
            auto node = f.first;
            if(lvl == v.size()){
                v.push_back({});
            }
                
            v[lvl].push_back(node -> val);

            if(node -> left)
            {
                q.push({node -> left, lvl + 1});
            }

            if(node -> right)
            {
                q.push({node -> right, lvl + 1});
            }
        }

        for(int i = 0; i < v.size(); i++)
        {
            if(i % 2)
            {
                reverse(v[i].begin(), v[i].end());
            }
        }

        return v;
    }
};