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
        vector<vector<int>> prev(m, vector<int>(n, 0)) ,curr(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (check(i, m - 1, j, n - 1, pizza)) 
                {
                    prev[i][j] = 1;
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
                        int down = prev[r + 1][j];
                        if(up && down)
                        {
                            ans = (ans + down) % MOD;
                        }
                    }

                    for(int c = j; c < n - 1; c++)
                    {
                        bool left = check(i, m - 1, j, c, pizza);
                        int right = prev[i][c + 1];
                        if(left && right)
                        {
                            ans = (ans + right) % MOD;
                        }
                    }
                    curr[i][j] = (int)ans;
                }
            }
            prev = curr;
        }

        return prev[0][0];
    }
};