class Solution {
public:
    void dfs(int i, vector<pair<int,int>> adj[], vector<bool>& vis, int& ans)
    {
        vis[i] = 1;
        for(auto it : adj[i])
        {
            int v = it.first, w = it.second; 
            ans = min(ans, w);
            if(!vis[v])
            {
                dfs(v, adj, vis, ans);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n + 1];
        int ans = INT_MAX;
        for(auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<bool> vis(n + 1, 0);
        dfs(1, adj, vis, ans);
        return ans;
    }
};