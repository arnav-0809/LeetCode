class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int minPos = -1, maxPos = -1, leftBound = -1, n = nums.size();
        
        for (int i = 0; i < n; i++) 
        {
            if (nums[i] < minK || nums[i] > maxK)
            {
                leftBound = i;
            }

            if (nums[i] == minK)
            {
                minPos = i;
            } 

            if (nums[i] == maxK)
            {
                maxPos = i;
            }
            ans += max(0, min(maxPos, minPos) - leftBound);
        }
        
        return ans;
    }
};