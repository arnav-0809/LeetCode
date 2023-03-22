class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dis(m, vector<int> (n, 1e9));
        dis[0][0] = 0;
        pq.push({0, {0, 0}});
        int row[] = {0, 0, 1, -1};
        int col[] = {1, -1, 0, 0};
        while(!pq.empty())
        {
            auto f = pq.top();
            int d = f.first, r = f.second.first, c = f.second.second;
            pq.pop();
            if(r == m - 1 && c == n - 1)
            {
                return d;
            }
            for(int i = 0; i < 4; i++)
            {
                int dr = r + row[i], dc = c + col[i];
                if(dr >= 0 && dc >= 0 && dr < m && dc < n)
                {
                    int effort = max(abs(heights[dr][dc] - heights[r][c]), d);
                    if(effort < dis[dr][dc])
                    {
                        dis[dr][dc] = effort;
                        pq.push({effort, {dr, dc}});
                    }
                }
            }
        }
        return 0;
    }
};