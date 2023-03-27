class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> prev(n, -1), curr(n, -1);
        prev[0] = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0)
                {
                    curr[j] = grid[0][0];
                }
                else
                {
                    int up = grid[i][j], left = grid[i][j];
                    if(i > 0)
                    {
                        up += prev[j];
                    }
                    else
                    {
                        up += 1e8;
                    }

                    if(j > 0)
                    {
                        left += curr[j - 1];
                    }
                    else
                    {
                        left += 1e8;
                    }
                    curr[j] = min(up, left);
                }
                prev = curr;
            }
        }
        return prev[n - 1];
    }
};