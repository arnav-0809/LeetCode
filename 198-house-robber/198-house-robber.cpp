class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0],prev2=0;
        for(int i=1;i<n;i++){
            int curr = max(nums[i]+prev2,prev);
             prev2=prev;
            prev=curr;
        }
        return prev;
    }
};