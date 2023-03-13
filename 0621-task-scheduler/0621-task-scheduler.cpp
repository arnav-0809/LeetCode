class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> m;
        int len = tasks.size();
        int maxi = INT_MIN;
        int time = 0;
        for(int i = 0; i < len; i++)
        {
            m[tasks[i]] += 1;
        }

        for(auto it : m)
        {
            maxi = max(maxi, it.second);
        }

        time = (maxi - 1) * (n + 1);
        for(auto it : m)
        {
            if(maxi == it.second)
            {
                time++;
            }
        }

        return max(time, len);
    }
    
};