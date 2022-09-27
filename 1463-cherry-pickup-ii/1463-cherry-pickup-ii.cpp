class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        
        for(int i = 0; i < n ; i++)
        {
            for(int j = 0; j < n ; j++)
            {
                if(i == j)
                {
                    dp[m-1][i][j] = grid[m-1][j];
                }
                else
                {
                     dp[m-1][i][j] = grid[m-1][i] + grid[m-1][j];
                }
            }
        }
        
        for(int i = m - 2; i >= 0; i--)
        {
            for(int j1 = 0; j1 < n; j1++)
            {
                for(int j2 = 0; j2 < n; j2++)
                {
                    int maxi = -1e8;
                    for(int dj1 = -1; dj1 <= 1; dj1++)
                    {
                        for(int dj2 = -1; dj2 <= 1; dj2++)
                        {
                            int value = 0;
                
                            if(j1 == j2)
                            {
                                value += grid[i][j1];
                            }
                            else
                            {
                                value += grid[i][j1]+grid[i][j2];
                            }
                            
                            if(j1 + dj1 >= 0 && j1 + dj1 < n && j2 + dj2 >= 0 && j2 + dj2 < n)
                            {
                                value += dp[i + 1][j1 + dj1][j2 + dj2];
                            }
                            else
                            {
                                value += -1e8;
                            }
                                
                            maxi = max(maxi, value);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
 
        return dp[0][0][n-1];
    }
};