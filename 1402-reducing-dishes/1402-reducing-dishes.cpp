class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(), sat.end());
        int n = sat.size();
        vector<int> next(n + 2, 0), curr(n + 2, 0);
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = 1; j <= n; j++)
            {
                int pick = sat[i] * j + next[j + 1];
                int notPick = next[j];
                curr[j] = max(pick, notPick);
            }
            next = curr;
        }
        return curr[1];
    }
};