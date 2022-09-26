class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int m=t.size();
        vector<vector<int>>dp;
        for(int i=0;i<m;i++){
            dp.push_back(vector<int>(i+1,-1e4+1));
        }
        for(int i=0;i<m;i++){
            dp[m-1][i]=t[m-1][i];
        }
        
        for(int i=m-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int up=t[i][j]+dp[i+1][j];
                int leftUp=t[i][j]+dp[i+1][j+1];
                dp[i][j]=min(up,leftUp);
            }
        }
        
        return dp[0][0];
    }
};