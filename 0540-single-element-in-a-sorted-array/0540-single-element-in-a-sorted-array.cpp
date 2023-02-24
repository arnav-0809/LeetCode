class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, mid = 0, r = n - 1;
        
        while(l <= r)
        {
            mid = l + (r - l) / 2;

            if(mid > 0 && nums[mid] == nums[mid - 1])
            {
                if(mid % 2)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 2;
                }
            }
            else if(mid + 1 < n && nums[mid] == nums[mid + 1])
            {
                if(mid % 2)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 2;
                }
            }
            else
            {
                return nums[mid];
            }
        }

        return nums[mid];
    }
};