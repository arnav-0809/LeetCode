class Solution {
public:
    void dfs(int i, vector<int>& vis, vector<int> adj[])
    {
        vis[i] = 1;
        for(auto it : adj[i])
        {
            if(!vis[it])
            {
                dfs(it, vis, adj);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(n > m + 1)
        {
            return -1;
        }

        vector<int> adj[n];
        for(auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(i, vis, adj);
            }
        }
        return ans - 1;
    }
};