class Solution {
public:
    void dfs(int i, int par, vector<pair<int, int>> adj[], int& count)
    {
        for(auto it : adj[i])
        {
            if(it.first != par)
            {
                count += it.second;
                dfs(it.first, i, adj, count);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,int>> adj[n];
        for(auto it : connections)
        {
            adj[it[0]].push_back({it[1], 1});
            adj[it[1]].push_back({it[0], 0});
        }
        int count = 0;
        dfs(0, -1, adj, count);
        return count;
    }
};