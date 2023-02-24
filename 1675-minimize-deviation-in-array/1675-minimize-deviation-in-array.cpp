class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> p;
        int n = nums.size();
        int mini = INT_MAX, ans = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] % 2)
            {
                p.push(2 * nums[i]);
                mini = min(mini, nums[i] * 2);
            }
            else
            {
                p.push(nums[i]);
                mini = min(mini, nums[i]);
            }
        }

        while(!p.empty())
        {
            int f = p.top();
            p.pop();
            ans = min(ans, f - mini);
            if(f % 2)
            {
                break;
            }
            mini = min(mini, f / 2);
            p.push(f / 2);
        }

        return ans;
    }
};