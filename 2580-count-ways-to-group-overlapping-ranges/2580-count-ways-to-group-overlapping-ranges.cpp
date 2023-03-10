class Solution {
public:
    int power(int x, int n)
    {
        int ans = 1;
        while(n--)
        {
            ans = (ans * x) % 1000000007;
        }
        return ans;
    }
    
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        int n = ranges.size();
        vector<vector<int>> v;
        v.push_back(ranges[0]);
        for(int i = 1; i < n; i++)
        {
            if(v.back()[1] >= ranges[i][0])
            {
                if(v.back()[1] < ranges[i][1])
                {
                    v.back()[1] = ranges[i][1];
                }
            }
            else
            {
                v.push_back(ranges[i]);
            }
        }
        int m = v.size();
        v.clear();
        return power(2, m);
    }
};