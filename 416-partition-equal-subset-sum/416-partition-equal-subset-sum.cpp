class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        
        if(sum%2){
            return false;
        }
        vector<bool>prev((sum/2)+1,false),temp((sum/2)+1,false);
        
        prev[0]=true,temp[0]=true;
        if(nums[0]<=sum/2)
            prev[nums[0]] = true;
        
        for(int i=1;i<n;i++){
            for(int target = 1;target<=sum/2;target++){
                bool notTake = prev[target];
                bool take = false;
                if(target>=nums[i])
                    take=prev[target-nums[i]];
        
                temp[target] = take || notTake;
            }
            prev=temp;
        }
        return prev[sum/2];
    }
};