class Solution {
public:
    bool check(vector<string>&s,int row,int col,int n){
        int row1 = row, col1 = col;
        while(row >= 0 && col >= 0)
        {    
            if(s[row][col] == 'Q')
                return false;
            
            row--, col--;
        }
        
        row = row1, col = col1;
        while(col >= 0)
        {    
            if(s[row][col] == 'Q')
                return false;
            
            col--;
        }
        
        row = row1, col = col1;
        while(row < n && col >= 0)
        {
            if(s[row][col] == 'Q')
                return false;
            
            row++, col--;
        }
        
        return true;
    }
    
    void sol(vector<vector<string>>&ans, vector<string>&s, int n, int col){
        if(n == col){
            ans.push_back(s);
            return;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(check(s, i, col, n))
            {
                s[i][col] = 'Q';
                sol(ans, s, n, col+1);
                s[i][col] = '.';
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string a = "";
        
        for(int i=0; i<n; i++)
        {
            a += '.';
        }
        
        vector<string>s(n, a);
        sol(ans, s, n, 0);
        return ans;
    }
};