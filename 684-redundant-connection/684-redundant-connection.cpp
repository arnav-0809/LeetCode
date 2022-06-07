class Solution {
public:
    int parent(int u,vector<int>&par){
        if(u==par[u])
            return u;
        return par[u]=parent(par[u],par);
    }
    void unionn(int u,int v,vector<int>&par,vector<int>&rank){
        u=parent(u,par);
        v=parent(v,par);
        if(rank[u]>rank[v]){
            par[v]=u;
        }else if(rank[v]<rank[u]){
            par[u]=v;
        }else{
            par[v]=u;
            rank[u]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        vector<int>rank(edges.size()+1,0);
        vector<int>par(edges.size()+1);
        for(int i=1;i<=edges.size();i++){
            par[i]=i;
        }
        
        for(int i=0;i<edges.size();i++){
            if(parent(edges[i][0],par)!=parent(edges[i][1],par)){
                unionn(edges[i][0],edges[i][1],par,rank);
            }else{
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
            }
        }
        return ans;
    }
};