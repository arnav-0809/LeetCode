class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redE, vector<vector<int>>& blueE) 
    {
        vector<vector<pair<int,int>>>v(n);
        vector<int>ans(n,-1);
        vector<vector<int>>vis(n,vector<int>(2,0));
        queue<vector<int>>q;
        int color=0,length=0;
        ans[0]=0;

        for(int i=0;i<redE.size();i++){
            v[redE[i][0]].push_back({redE[i][1],0});
        }

        for(int i=0;i<blueE.size();i++){
            v[blueE[i][0]].push_back({blueE[i][1],1});
        }
        
        q.push({0,0,-1});
        vis[0][0]=1;
        vis[0][1]=1;

        while(!q.empty()){
            auto x=q.front();
            length=x[1];
            color=x[2];
            q.pop();
            
            for(auto it:v[x[0]]){
                if(vis[it.first][it.second]==0 && color!=it.second){
                    vis[it.first][it.second]=1;
                    q.push({it.first, length + 1, it.second});
                    if (ans[it.first] == -1){
                        ans[it.first] = length+1;
                    } 
                }
            }
        }

        return ans;
    }
};