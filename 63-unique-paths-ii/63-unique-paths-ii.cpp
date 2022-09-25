class Solution {
public:
    int sol(int m, int n, vector<vector<int>>&dp,vector<vector<int>>&og){
        if(m<0 || n<0) 
            return 0;
        
        if(og[m][n]==1)
            return 0;
        
        if(m==0 && n==0)
            return 1;
        
        if(dp[m][n]!=-1)return dp[m][n];
        
        int up=sol(m-1,n,dp,og);
        int left=sol(m,n-1,dp,og);
        return dp[m][n]=up+left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int m = og.size();
        int n = og[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return sol(m-1,n-1,dp,og);
    }
};