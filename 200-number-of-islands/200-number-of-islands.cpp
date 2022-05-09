class Solution {
public:
    void dfs(int i,int j,int m,int n,vector<vector<char>>&grid){
        if(i>=m || j>=n|| i<0 || j<0 || grid[i][j]!='1')
            return;
        grid[i][j]='2';
        dfs(i,j+1,m,n,grid);
        dfs(i,j-1,m,n,grid);
        dfs(i+1,j,m,n,grid);
        dfs(i-1,j,m,n,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        if(!m) return 0;
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,m,n,grid);
                    count++;
                }
            }
        }
        return count;
    }
};