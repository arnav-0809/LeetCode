class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        if(m == 0)
        {
           return n;
        }

        if(n == 0)
        {
            return m;
        }
        
        for(int i = 1; i <= n; i++)
        {
            prev[i] = i;
        }

        for(int i = 1; i <= m; i++)
        {
            curr[0] = i;
            for(int j = 1; j <= n; j++)
            {
                if(word1[i - 1] == word2[j - 1])
                {
                    curr[j] = prev[j - 1];
                }
                else
                {
                    int insert = curr[j - 1];
                    int del = prev[j];
                    int replace = prev[j - 1];
                    curr[j] = min(insert, min(del, replace)) + 1;
                }
            }
            prev = curr;
        }

        return prev[n];
    }
};