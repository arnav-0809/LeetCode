class Solution {
public:
    int sol(vector<int>&dp, vector<int>&nums,int ind){
        if(ind==0)
            return nums[ind];
        
        if(ind<0)
            return 0;
        
        if(dp[ind]!=-1)return dp[ind];
        int pick = nums[ind] + sol(dp,nums,ind-2);
        int notPick = sol(dp,nums,ind-1);
        
        return dp[ind]=max(pick,notPick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return sol(dp,nums,n-1);
    }
};