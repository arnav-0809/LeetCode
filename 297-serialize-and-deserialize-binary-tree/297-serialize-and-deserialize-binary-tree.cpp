/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    void sol(TreeNode*root,string&s){
        if(root==NULL)
            return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*f=q.front();
            q.pop();
            if(f==NULL)
            {
                s+="#";
                s+=",";
            }else{
                s+=to_string(f->val);
                s+=",";
                q.push(f->left);
                q.push(f->right);
            }
        }
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        sol(root,s);
        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string d) {
        if(d.length()==0)
            return NULL;
        queue<TreeNode*>q;
        stringstream ss(d);
        string str;
        getline(ss,str,',');
        TreeNode*root=new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode*f=q.front();
            q.pop();
            getline(ss,str,',');
            
            if(str=="#"){
                f->left=NULL;
            }else{
                TreeNode*l=new TreeNode(stoi(str));
                f->left=l;
                q.push(l);
            }
            
            getline(ss,str,',');
            if(str=="#"){
                f->right=NULL;
            }else{
                TreeNode*r=new TreeNode(stoi(str));
                f->right=r;
                q.push(r);
            }    
        }
        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));