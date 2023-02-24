class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = 0, j = 1, n = nums.size();
        while(j < n)
        {
            if(nums[i] == nums[j])
            {
                i += 2;
                j += 2;
            }
            else
            {
                return nums[i];
            }
        }

        return nums[i];
    }
};