const int N = 1e6 + 1;
vector<int> prime(N + 1);

class Solution {
public:
    void sieve()
    {
        for(int i = 1; i < N; i++)
        {
            prime[i] = i;
        }

        for (int p = 2; p * p <= N; p++) 
        {
            if (prime[p] == p) 
            {
                for (int i = p * p; i <= N; i += p)
                {
                    if(prime[i] == i)
                    {
                        prime[i] = p;
                    }
                }
            }
        }
    }

    int findValidSplit(vector<int>& nums) {
        sieve();
        map<int, int> m;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int y = nums[i];
            while(y != 1)
            {
                m[prime[y]] = i;
                y /= prime[y];
            }
        }
        
        int minIdx = 0;
        for(int i = 0; i <= minIdx; i++)
        {
            int y = nums[i];
            while(y != 1)
            {
                minIdx = max(m[prime[y]], minIdx);
                y /= prime[y];
            }
        }

        return minIdx != n - 1 ? minIdx : -1;
    }
};