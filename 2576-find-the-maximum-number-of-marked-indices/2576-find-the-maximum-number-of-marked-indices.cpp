class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = n / 2;
        while(i < n / 2 && j < n)
        {
            if(2 * nums[i] <= nums[j])
            {
                i++, j++;
            }
            else
            {
                j++;
            }
        }
        
        return i * 2;
    }
};