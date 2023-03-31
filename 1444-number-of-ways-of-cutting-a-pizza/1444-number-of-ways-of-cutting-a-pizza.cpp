class Solution {
public:
    int MOD = 1e9 + 7;
    bool check(int sRow, int eRow, int sCol, int eCol, vector<string>& pizza)
    {
        for(int i = sRow; i <= eRow; i++)
        {
            for(int j = sCol; j <= eCol; j++)
            {
                if(pizza[i][j] == 'A')
                {
                    return true;
                }
            }
        }
        return false;
    }

    int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        int n = pizza[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (check(i, m - 1, j, n - 1, pizza)) 
                {
                    dp[i][j][0] = 1;
                }
            }
        }

        for(int l = 1; l < k; l++)
        {
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    long long ans = 0;
                    for(int r = i; r < m - 1; r++)
                    {
                        bool up = check(i, r, j, n - 1, pizza);
                        int down = dp[r + 1][j][l - 1];
                        if(up && down)
                        {
                            ans = (ans + down) % MOD;
                        }
                    }

                    for(int c = j; c < n - 1; c++)
                    {
                        bool left = check(i, m - 1, j, c, pizza);
                        int right = dp[i][c + 1][l - 1];
                        if(left && right)
                        {
                            ans = (ans + right) % MOD;
                        }
                    }
                    dp[i][j][l] = (int)ans;
                }
            }
        }

        return dp[0][0][k - 1];
    }
};