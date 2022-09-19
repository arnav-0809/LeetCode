class Solution {
public:
    void sol(vector<vector<string>>&ans, vector<string>&s, vector<int>&lowerD, vector<int>&upperD,                    vector<int>&leftRow, int n, int col)
    {
        if(col == n)
        {
            ans.push_back(s);
            return;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(lowerD[i + col] == 0 && upperD[n - 1 + col - i] == 0 && leftRow[i] == 0)
            {
                s[i][col] = 'Q';
                lowerD[i + col] = 1;
                upperD[n - 1 + col - i] = 1;
                leftRow[i] = 1;
                
                sol(ans, s, lowerD, upperD, leftRow, n, col + 1);
                
                s[i][col] = '.';
                lowerD[i + col] = 0;
                upperD[n - 1 + col - i] = 0;
                leftRow[i] = 0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>>ans;
        string a = "";
        
        for(int i = 0; i < n; i++)
        {
            a += '.';
        }
        
        vector<string>s(n, a);
        vector<int>lowerD(2 * n - 1, 0), upperD(2 * n - 1, 0), leftRow(n, 0);
        
        sol(ans, s, lowerD, upperD, leftRow, n , 0);
        
        return ans;
    }
};