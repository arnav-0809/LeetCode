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
        int n = ranges.size(), m = 1;
        int lastRange = ranges[0][1];
        for(int i = 1; i < n; i++)
        {
            if(lastRange >= ranges[i][0])
            {
                if(lastRange < ranges[i][1])
                {
                    lastRange = ranges[i][1];
                }
            }
            else
            {
                m += 1;
                lastRange = ranges[i][1];
            }
        }
        
        return power(2, m);
    }
};