class Solution {
public:
    int minDist(string word1, string word2, int m, int n, vector<vector<int>> &dp)
    {
        if(m == 0)
        {
           return n;
        }

        if(n == 0)
        {
            return m;
        }

        if(dp[m][n] != -1)
        {
            return dp[m][n];
        }

        if(word1[m - 1] == word2[n - 1])
        {
            return dp[m][n] = minDist(word1, word2, m - 1, n - 1, dp);
        }
        else
        {
            int insert = minDist(word1, word2, m, n - 1, dp);
            int del = minDist(word1, word2, m - 1, n, dp);
            int replace = minDist(word1, word2, m - 1, n - 1, dp);
            return dp[m][n] = min(insert, min(del, replace)) + 1;
        }
    }

    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        return minDist(word1, word2, m, n, dp);
    }
};