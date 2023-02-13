class Solution {
public:
    int countOdds(int low, int high) {
        if(low == high)
        {
            return (low % 2);
        }

        int x = high - low - 1, ans = 0;
        if(high % 2 && low % 2)
        {
            ans = (x / 2) + 2;
        }
        else
        {
            ans = (x / 2) + 1;
        }

        return ans;
    }
};