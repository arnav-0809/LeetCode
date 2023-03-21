class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long sub = 0, j;
        for(int i = 0; i < n; i++)
        {
            j = 0;
            while(i < n && nums[i] == 0)
            {
                j++;
                i++;
            }

            sub += (j * (j + 1)) / 2;
        }
        return sub;
    }
};