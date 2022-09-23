class Solution {
public:
    int robMax(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0],prev2=0;
        for(int i=1;i<n;i++){
            int curr = max(nums[i]+prev2,prev);
             prev2=prev;
            prev=curr;
        }
        return prev;
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int>temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        return max(robMax(temp1),robMax(temp2));
    }
};