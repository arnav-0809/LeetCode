class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        q.push({0, {src, 0}});
        while(!q.empty())
        {
            auto f = q.front();
            int stops = f.first, i = f.second.first, d = f.second.second;
            q.pop();
            if(stops > k)
            {
                break;
            }
            for(auto it : adj[i])
            {
                int x = it.first, prevD = it.second;
                if(prevD + d < dist[x])
                {
                    dist[x] =  prevD + d;
                    q.push({stops + 1, {x, dist[x]}});
                }
            }
        }

        if(dist[dst] == 1e9)
        {
            return -1;
        }
        return dist[dst];
    }
};