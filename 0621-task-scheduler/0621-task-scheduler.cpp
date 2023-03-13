class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        map<char, int> m;
        int len = tasks.size();
        for(int i = 0; i < len; i++)
        {
            m[tasks[i]] += 1;
        }

        for(auto it : m)
        {
            pq.push(it.second);
        }

        m.clear();
        int time = 0;
        while(!pq.empty())
        {
            int cycle = n + 1;
            vector<int> rem;
            while(cycle && !pq.empty())
            {
                auto it = pq.top();
                pq.pop();
                if(it > 1)
                {
                    rem.push_back(it - 1);
                }
                cycle--;
                time++;
            }

            for(auto i : rem)
            {
                pq.push(i);
            }

            if(pq.empty())
            {
                break;
            }
            time += cycle;
        }
        return time;
    }
    
};