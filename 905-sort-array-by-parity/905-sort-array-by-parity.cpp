class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            if(nums[l]%2==1 && nums[r]%2==0)
            {
                swap(nums[l],nums[r]);
                l++;
                r--;
            }else if(nums[l]%2==0 && nums[r]%2==1){
                l++;
                r--;
            }else if(nums[l]%2==0 && nums[r]%2==0){
                l++;
            }else if(nums[l]%2==1 && nums[r]%2==1){
                r--;
            }
        }
        return nums;
    }
};