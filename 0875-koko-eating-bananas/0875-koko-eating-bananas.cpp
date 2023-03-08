class Solution {
public:
    int getCeil(int pile, int eatingSpeed)
    {
        if(pile % eatingSpeed != 0)
        {
            return (pile / eatingSpeed) + 1;
        }
        return pile / eatingSpeed;
    }

    long long int timeTaken(vector<int>& piles, int eatingSpeed)
    {
        long long int hoursTaken = 0, n = piles.size();
        for(int i = 0; i < n; i++)
        {
            hoursTaken += getCeil(piles[i], eatingSpeed);
        }
        return hoursTaken;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9;
        while(l <= r)
        {
            int m = l + (r - l) / 2;
            if(timeTaken(piles, m) <= h)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1; 
            }
        }
        return r + 1;
    }
};