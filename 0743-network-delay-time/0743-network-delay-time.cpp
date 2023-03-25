class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 1];
        for(auto it : times)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0;
        while(!pq.empty())
        {
            auto f = pq.top();
            pq.pop();
            int dist = f.first;
            int i = f.second;
            if(dist > dis[i])
            {
                continue;
            }

            for(auto it : adj[i])
            {
                int x = it.first, d = it.second;
                if(d + dist < dis[x])
                {
                    dis[x] = d + dist;
                    pq.push({dis[x], x});
                } 
            }
        }

        int ans = INT_MIN;
        for(int i = 1; i <= n; i++)
        {
            ans = max(ans, dis[i]);
        }

        if(ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};