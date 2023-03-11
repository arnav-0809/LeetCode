class Solution {
public:
    map<pair<int, int>, int> m;
    int sol(vector<vector<int>>& adj, int src, vector<bool>& vis){
        vis[src] = 1;
        int ans = 0;
        for(auto i : adj[src])
        {
            if(!vis[i])
            {
                ans += (m.count({src, i}) + sol(adj, i, vis));
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int k, int src, int ans, int& rCount){
        if(ans >= k) 
        {
            rCount += 1;
        }

        vis[src] = 1;
        for(auto i : adj[src])
        {
            if(!vis[i])
            {
                dfs(adj, vis, k, i, ans - m.count({src, i}) + m.count({i, src}), rCount);
            }
        }
    }
    
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1, rCount = 0;
        vector<vector<int>> adj(n);
        vector<bool> vis(n, 0);
        for(auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        for(auto i : guesses)
        {
            m[{i[0], i[1]}] = 1;
        }

        int ans = sol(adj, 0, vis);
        fill(vis.begin(), vis.end(), 0);
        dfs(adj, vis, k, 0, ans, rCount);
        return rCount;
    }
};