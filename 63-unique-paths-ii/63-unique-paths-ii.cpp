class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int m = og.size();
        int n = og[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (og[i][j]==1)dp[i][j]= 0;
                else if(i==0 && j==0)dp[0][0]=1;
                else{
                    int up=0,left=0;
                    if(i>0)
                        up = dp[i-1][j];
                    if(j>0)
                        left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};