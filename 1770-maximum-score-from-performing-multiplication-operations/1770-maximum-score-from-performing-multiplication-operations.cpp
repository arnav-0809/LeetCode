class Solution {
    vector<vector<int>>dp;
public:
    int sol(vector<vector<int>>&dp,vector<int>& n, vector<int>& m, int i,int j){
        if(i==m.size()){
            return 0;
        }
        
        if(dp[i][j]!=INT_MIN){
            return dp[i][j];
        }
        
        int f = n[j] * m[i] + sol(dp,n,m,i+1,j+1);
        int s = n[n.size()-1-(i-j)] * m[i] + sol(dp,n,m,i+1,j);
        
        return dp[i][j] = max(f,s);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        dp.resize(multipliers.size()+1,vector<int>(multipliers.size(),INT_MIN));
        return sol(dp,nums,multipliers,0,0);
    }
};