class Solution {
public:
    void bfs(int i,vector<vector<int>>& graph,vector<int>&vis,bool&ans){
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int f=q.front();
            q.pop();
            for(auto it:graph[f]){
                if(vis[it]==-3 && vis[f]==-1){
                    q.push(it);
                    vis[it]=-2;
                }else if(vis[it]==-3 && vis[f]==-2){
                    q.push(it);
                    vis[it]=-1;
                }else if((vis[it]==-2 && vis[f]==-2) ||(vis[it]==-1 && vis[f]==-1)){
                    ans=false;
                    return;
                }
            }
        }
        ans=true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        bool ans=false;
        vector<int>vis(graph.size(),-3);
        for(int i=0;i<graph.size();i++){
            if(vis[i]==-3){
                vis[i]=-2;
                bfs(i,graph,vis,ans);
                if(ans==false){
                    return false;
                }
            }
        }
        return true;
    }
};