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
    TreeNode*ans(vector<int>& nums,int l,int r){
        if(l>r)
            return NULL;
        int mid=l+(r-l)/2;
        TreeNode*t=new TreeNode(nums[mid]);
        t->left=ans(nums,l,mid-1);
        t->right=ans(nums,mid+1,r);
        return t;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return ans(nums,0,nums.size()-1);
    }
};