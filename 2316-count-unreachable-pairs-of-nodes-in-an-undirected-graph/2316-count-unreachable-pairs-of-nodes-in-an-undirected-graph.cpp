class Solution {
public:
    void dfs(int i, vector<bool>& vis, vector<int> adj[], int& count)
    {
        vis[i] = true;
        count++;
        for(auto it : adj[i])
        {
            if(!vis[it])
            {
                dfs(it, vis, adj, count);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> vis(n, false);
        vector<int> ans;
        long long int totalCount = 0;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                int count = 0;
                dfs(i, vis, adj, count);
                totalCount += count;
                ans.push_back(count);
            }
        }

        int m = ans.size();
        long long int pairs = 0;
        cout<<totalCount;
        for(int i = 0; i < m; i++)
        {
            long long int x = ans[i];
            pairs += (totalCount - x) * x;
        }
        return pairs / 2;
    }
};