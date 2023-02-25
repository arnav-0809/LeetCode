class Solution {
public:
    bool sol(int val, vector<int>& weights, int days)
    {
        int d = 1, n = weights.size(), sum = 0;

        for(int i = 0; i < n; i++)
        {
            if(weights[i] > val)
            {
                return false;
            }

            if(sum + weights[i] > val)
            {
                sum = weights[i];
                d++;
            }
            else
            {
                sum += weights[i];
            }
        }

        return d <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int l = 1, r = 1e9, mid = 0;
        while(l <= r)
        {
            mid = l + (r - l) / 2;

            if(sol(mid, weights, days))
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return r + 1;
    }
};