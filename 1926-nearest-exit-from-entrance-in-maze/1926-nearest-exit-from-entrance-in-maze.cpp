class Solution {
public:
   
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        int m = maze.size();
        int n = maze[0].size();
        queue<vector<int>>q;
        q.push({e[0],e[1],0});
        maze[e[0]][e[1]]='+';
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            for(auto it:dir){
                int row=it[0]+f[0];
                int col=it[1]+f[1];
                if(row>=0 && row<m && col>=0 && col<n && maze[row][col]=='.'){
                    if(row==0 || row==m-1 || col==0 || col==n-1){
                        return f[2]+1;
                    }
                    int dis=f[2]+1;
                    maze[row][col]='+';
                    q.push({row,col,dis});
                }
            }
        }
        return -1;
        
    }
};