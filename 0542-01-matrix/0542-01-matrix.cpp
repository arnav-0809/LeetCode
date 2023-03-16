class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), br = 0;
        vector<vector<int>> mx(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({{i, j}, 0});
                }
            }
        }

        int row[] = {0, 0, 1, -1};
        int col[] = {1, -1, 0, 0};
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int i = it.first.first, j = it.first.second, d = it.second;
            for(int k = 0; k < 4; k++)
            {
                int r = i + row[k];
                int c = j + col[k];
                if(r >= 0 && c >= 0 && r < m && c < n && mat[r][c] == 1)
                {
                    mx[r][c] = d + 1;
                    mat[r][c] = 2;
                    q.push({{r, c}, d + 1});
                }
            }
        }
        return mx;
    }
};