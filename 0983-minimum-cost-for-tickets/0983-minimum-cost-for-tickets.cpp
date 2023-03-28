class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int totalDays = 365, m = days.size();
        vector<int> dp(totalDays + 2, 365 * 1000);
        vector<int> pass{1, 7, 30};
        vector<bool> travel(totalDays + 1, false);
        for(int i = 0; i < m; i++)
        {
            travel[days[i]] = true;
        }
        dp[totalDays + 1] = 0;
        for(int i = totalDays; i >= 1; i--)
        {
            if(!travel[i])
            {
                dp[i] = dp[i + 1];
            }
            else
            {
                for(int j = 0; j < 3; j++)
                {
                    dp[i] = min(dp[i], costs[j] + dp[min(i + pass[j], totalDays + 1)]);
                }
            }
        }
        return dp[1];
    }
};