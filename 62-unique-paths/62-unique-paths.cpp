class Solution {
public:
    int sol(int m,int n,int i,int j,vector<vector<int>>&dp){
        if(i>=m || j>=n){
            return 0;
        }
        
        if(i==m-1 && j==n-1){
            return 1;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=sol(m,n,i+1,j,dp)+sol(m,n,i,j+1,dp);
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans=sol(m,n,0,0,dp);
        if(m==1 && n==1)
            return ans;
        return dp[0][0];
    }
};