class Solution {
public:
    void dfs(int i,vector<vector<int>>& graph,vector<int>&vis,bool&ans){
        for(auto it:graph[i]){
            if(vis[it]==-3 && vis[i]==-1){
                vis[it]=-2;
                dfs(it,graph,vis,ans);
            }else if(vis[it]==-3 && vis[i]==-2){
                vis[it]=-1;
                dfs(it,graph,vis,ans);
            }else if((vis[it]==-2 && vis[i]==-2) ||(vis[it]==-1 && vis[i]==-1)){
                ans=false;
                return;
            }
        }
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        bool ans=true;
        vector<int>vis(graph.size(),-3);
        for(int i=0;i<graph.size();i++){
            if(vis[i]==-3){
                vis[i]=-2;
                dfs(i,graph,vis,ans);
                if(ans==false){
                    return false;
                }
            }
        }
        return true;
    }
};