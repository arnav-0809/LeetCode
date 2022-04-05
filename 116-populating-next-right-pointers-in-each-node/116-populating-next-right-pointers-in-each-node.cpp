/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        vector<pair<Node*,int>>v;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            pair<Node*,int>p=q.front();
            q.pop();
            Node*f=p.first;
            int lvl=p.second;
            v.push_back({f,lvl});
            if(f->left)
                q.push({f->left,lvl+1});
            if(f->right)
                q.push({f->right,lvl+1});
        }
        
        for(int i=0;i<v.size()-1;i++){
            cout<<v[i].first->val<<" ";
            if(v[i].second==v[i+1].second){
                v[i].first->next=v[i+1].first;
            }else{
                v[i].first->next=NULL;
            }
        }

        return root;
    }
};