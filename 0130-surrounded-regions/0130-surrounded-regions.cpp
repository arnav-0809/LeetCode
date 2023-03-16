class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<char>>& board)
    {
        if(i < 0 || j < 0 || i >= m || j >= n)
        {
            return;
        }
        if(board[i][j] != 'O')
        {
            return;
        }

        board[i][j] = '#';
        dfs(i + 1, j, m, n, board);
        dfs(i - 1, j, m, n, board);
        dfs(i, j + 1, m, n, board);
        dfs(i, j - 1, m, n, board);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int j = 0; j < n; j++)
        {
            if(board[0][j] == 'O')
            {
                dfs(0, j, m, n, board);
            }

            if(board[m - 1][j] == 'O')
            {
                dfs(m - 1, j, m, n, board);
            }
        }

        for(int i = 0; i < m; i++)
        {
            if(board[i][0] == 'O')
            {
                dfs(i, 0, m, n, board);
            }

            if(board[i][n - 1] == 'O')
            {
                dfs(i, n - 1, m, n, board);
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                if(board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};