class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        vector<vector<int>>d(n,vector<int>(n,INT_MAX));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    d[i][j]=0;
                }
            }
        }

        int farDist=-1;

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            vector<int>dx={0,0,1,-1};
            vector<int>dy={1,-1,0,0};

            for(int i=0;i<4;i++){
                int x1=x+dx[i];
                int y1=y+dy[i];
                if(x1>=0 && y1>=0 && x1<n && y1<n){
                    if(1+d[x][y]<d[x1][y1]){
                        d[x1][y1]=1+d[x][y];
                        q.push({x1,y1});
                        farDist=d[x1][y1];
                    }
                }
            }
        }

        return farDist;
    }
};