class Solution {
public:
    int sol(int i,int j,int n,vector<vector<int>>& t,vector<vector<int>>&dp){
        if(i==n-1){
            return t[n-1][j];
        }
        
        if(dp[i][j]!=-1e4+1)return dp[i][j];
        
        int up=t[i][j]+sol(i+1,j,n,t,dp);
        int leftUp=t[i][j]+sol(i+1,j+1,n,t,dp);

        return dp[i][j]=min(up,leftUp);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>>dp;
        for(int i=0;i<m;i++){
            dp.push_back(vector<int>(i+1,-1e4+1));
        }
        return sol(0,0,m,triangle,dp);
    }
};