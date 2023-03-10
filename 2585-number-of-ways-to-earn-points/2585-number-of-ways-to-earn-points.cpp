class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<int> cur(target + 1, 0), pre(target + 1, 0);
        pre[0] = 1;

        for(int i = n - 1; i >= 0; i--)
        {
            for(int k = target; k >= 0; k--)
            {
                int ans = 0;
                for(int j = 0; j <= types[i][1] * types[i][0]; j += types[i][1])
                {
                    if(k - j >= 0)
                    {
                        ans = (ans + pre[k - j]) % 1000000007;
                    }
                    else 
                    {
                        break;
                    }
                }
                cur[k] = ans;
            }
            pre = cur;
        }
        return pre[target];
    }
};