class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        set<int> s;
        int n = nums.size(), i = 0;
        for(int i = 0; i < n; i++)
        {
            s.insert(nums[i]);
        }

        while(s.find(1 << i) != s.end())
        {
            i++;
        }
        return 1 << i;
    }
};