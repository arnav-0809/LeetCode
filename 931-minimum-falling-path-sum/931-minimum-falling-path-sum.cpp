class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int mini = 1e9;
        vector<int>prev(m, -101);
        
        for(int i = 0; i < m; i++)
        {
            prev[i] = matrix[0][i];
        }
        
        vector<int>temp(m, -101);
        
        for(int i = 1; i < m; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int up = matrix[i][j] + prev[j];
                
                int upLeft = matrix[i][j];
                if(j == 0)
                {
                    upLeft += 1e9;
                }
                else
                {
                    upLeft += prev[j-1];
                }
                
                int upRight = matrix[i][j];
                if(j == m-1)
                {
                    upRight += 1e9;
                }
                else
                {
                    upRight += prev[j+1];
                }
                
                temp[j] = min(up, min(upLeft, upRight)); 
            }
            prev = temp;
        }
        
        for(int i = 0; i < m; i++)
        {
            mini = min(mini, prev[i]);
        }
        
        return mini;
    }
};