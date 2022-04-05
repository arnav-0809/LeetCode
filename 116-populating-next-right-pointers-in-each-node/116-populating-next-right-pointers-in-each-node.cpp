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
    void sol(Node*root,Node*parent,bool exist){
        if(root==NULL)
            return;
        if(exist){
            root->next=parent->right;
        }else{
            if(parent==root){
                root->next=NULL;
            }
            else if(parent->next){
                root->next=parent->next->left;
            }else{
                root->next=NULL;
            }
        }
        sol(root->left,root,true);
        sol(root->right,root,false);
    }
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        sol(root,root,false);
        return root;
    }
};