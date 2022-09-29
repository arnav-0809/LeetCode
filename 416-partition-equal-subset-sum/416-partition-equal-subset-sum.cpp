class Solution {
public:
    bool sol(vector<int>& nums,int i,int target,vector<vector<int>>&dp){
        if(target==0)
            return true;
        if(i==0)
            return target==nums[0];
        
        if(dp[i][target]!=-1)return dp[i][target];
        
        bool notTake = sol(nums,i-1,target,dp);
        bool take = false;
        if(target>=nums[i])
            take=sol(nums,i-1,target-nums[i],dp);
        
        return dp[i][target] = take || notTake;
    }
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        
        if(sum%2){
            return false;
        }
        vector<vector<int>>dp(n,vector<int>((sum/2)+1,-1));
        return sol(nums,n-1,sum/2,dp);
    }
};