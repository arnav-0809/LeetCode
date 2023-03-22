class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1)
        {
            return -1;
        }
        if(n == 1)
        {
            return 1;
        }
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        dis[0][0] = 1;
        q.push({1, {0, 0}});
        int row[] = {0, 0, 1, -1, -1, -1, 1, 1};
        int col[] = {1, -1, 0, 0, -1, 1, -1, 1}; 
        while(!q.empty())
        {
            auto f = q.front();
            int d = f.first;
            int r = f.second.first;
            int c = f.second.second;
            q.pop();
            for(int i = 0; i < 8; i++)
            {
                int dr = r + row[i];
                int dc = c + col[i];
                if(dr >= 0 && dc >= 0 && dr < n && dc < n && grid[dr][dc] == 0 && 1 + d < dis[dr][dc])
                {
                    if(dr == n - 1 && dc == n - 1)
                    {
                        return 1 + d;
                    }
                    dis[dr][dc] = 1 + d;
                    q.push({1 + d, {dr, dc}});
                }
            }
        }
        return -1;
    }
};