class Solution {
public:
    void dfs(int i, vector<bool>& vis, vector<int>& edges, map<int, int>& m, int& ans)
    {
        vis[i] = true;
        int node = edges[i];
        if(node != -1 && !vis[node])
        {
            m[node] = m[i] + 1;
            dfs(node, vis, edges, m, ans);
        }
        else if(node != -1 && m.count(node))
        {
            ans = max(ans, m[i] + 1 - m[node]);
        }
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size(), ans = -1;
        vector<bool> vis(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                map<int, int> m;
                dfs(i, vis, edges, m, ans);
            }
        }
        return ans;
    }
};