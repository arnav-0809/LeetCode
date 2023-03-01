class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][1] > 1 && grid[1][0] > 1)
        {
            return -1;
        }

        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> visited(m, vector<int>(n, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) 
        {
            int t = pq.top()[0], i = pq.top()[1], j = pq.top()[2];
            pq.pop();

            if (i == m - 1 && j == n - 1) 
            {
                return t;
            }

            if (visited[i][j])
            {
                continue;
            }

            visited[i][j] = 1;

            for (auto dr: dirs) 
            {
                int r = i + dr[0], c = j + dr[1];
                if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c])
                {
                    continue;
                } 

                int w = (grid[r][c] - t) % 2 == 0;
                pq.push({max(grid[r][c] + w, t + 1), r, c});
            }
        }
        return -1;
    }
};