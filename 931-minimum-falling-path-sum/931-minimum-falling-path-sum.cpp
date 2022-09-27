class Solution {
public:
    int sol(int m,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(m<0 || n<0 || n>=matrix.size()){
            return 1e9;
        }
        
        if(m==0){
            return matrix[0][n];
        }
        
        if(dp[m][n]!=-101)return dp[m][n];
        
        int up=matrix[m][n]+sol(m-1,n,matrix,dp);
        int upLeft =matrix[m][n]+sol(m-1,n-1,matrix,dp);
        int upRight=matrix[m][n]+sol(m-1,n+1,matrix,dp);
        
        return dp[m][n]=min(up,min(upLeft,upRight));  
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int mini=1e9;
         vector<vector<int>>dp(m,vector<int>(m,-101)); 
        for(int i=0;i<m;i++){
            mini=min(mini,sol(m-1,i,matrix,dp));
        }
        return mini;
    }
};