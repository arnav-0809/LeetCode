class Solution {
public:
    static bool compare(vector<int>& t1, vector<int>& t2)
    {
        return t1[1] < t2[1];
    }

    int findMinimumTime(vector<vector<int>>& tasks) {
        map<int, int> m;
        sort(tasks.begin(), tasks.end(), compare);
        for(auto it : tasks)
        {
            int s = it[0], e = it[1], dur = it[2];
            for(int i = s; i <= e; i++)
            {
                if(m.count(i))
                {
                    dur--;
                }
            }
            for(int j = e; dur > 0; j--)
            {
                if(m.count(j))
                {
                    continue;
                }
                dur--;
                m[j] = 1;
            }
        }

        return m.size();
    }
};