class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int mini = 1e9;
        vector<vector<int>>dp(m, vector<int>(m, -101));
        
        for(int i = 0; i < m; i++)
        {
            dp[0][i] = matrix[0][i];
        }
        
        for(int i = 1; i < m; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int up = matrix[i][j] + dp[i-1][j];
                
                int upLeft = matrix[i][j];
                if(j == 0)
                {
                    upLeft += 1e9;
                }
                else
                {
                    upLeft += dp[i-1][j-1];
                }
                
                int upRight = matrix[i][j];
                if(j == m-1)
                {
                    upRight += 1e9;
                }
                else
                {
                    upRight += dp[i-1][j+1];
                }
                
                dp[i][j] = min(up, min(upLeft, upRight)); 
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            mini = min(mini, dp[m-1][i]);
        }
        
        return mini;
    }
};