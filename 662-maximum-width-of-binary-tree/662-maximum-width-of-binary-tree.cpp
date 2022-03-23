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
#define ll unsigned long long int
class Solution {
    void solve(map<ll,set<ll>>&ans,TreeNode*root,ll ans1,ll l){
        if(root==NULL)
            return;
        if(ans.find(l)==ans.end()){
            ans[l]={ans1};
        }else{
            ans[l].insert(ans1);
        }
        solve(ans,root->left,2*ans1,l+1);
        solve(ans,root->right,2*ans1+1,l+1);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        ll ans1=0,l=0;
        map<ll,set<ll>>ans;
        ll maxi=0;
        if(root==NULL)
            return maxi;
        solve(ans,root,ans1,l);
        for(auto it:ans){
            auto e=it.second;
            maxi=max(maxi,*e.rbegin()-*e.begin()+1);
        }
        return maxi;
    }
};