class Solution {
public:
    long long int dfs(int i, vector<int>& vis, vector<vector<int>>& adj, 
    int& seats, long long int &minCost) {
        long long int peeps = 1;
        vis[i] = 1;
        for (auto& it : adj[i]) {
            if (!vis[it]) {
                peeps += dfs(it, vis, adj, seats, minCost);
            }
        }

        if (i != 0) {
            minCost += ceil((double)peeps / seats);
        }
        return peeps;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        long long int minCost = 0;
        vector<vector<int>> adj(n);
        vector<int>vis(n, 0);

        for (auto& road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }

        dfs(0, vis, adj, seats, minCost);
        return minCost;
    }
};