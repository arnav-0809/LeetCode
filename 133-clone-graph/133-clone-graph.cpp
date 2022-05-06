/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node*dfs(Node*n,map<Node*,Node*>&m){
        vector<Node*>v;
        Node*clone=new Node(n->val);
        m[n]=clone;
        for(auto it:n->neighbors){
            if(m.find(it)!=m.end()){
                v.push_back(m[it]);
            }else{
                v.push_back(dfs(it,m));
            }
        }
        clone->neighbors=v;
        return clone;
    }
public:
    Node* cloneGraph(Node* node) {
        map<Node*,Node*>m;
        if(node==NULL)
            return NULL;
        if(node->neighbors.size()==0){
            Node*clone=new Node(node->val);
        }
        
        return dfs(node,m);
    }
};