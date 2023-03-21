class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> revAdj[n];
        vector<int> in(n, 0), ans;
        for(int i = 0; i < n; i++)
        {
            for(auto it : graph[i])
            {
                revAdj[it].push_back(i);
                in[i]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(in[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            auto f = q.front();
            q.pop();
            ans.push_back(f);
            for(auto it : revAdj[f])
            {
                in[it]--;
                if(in[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};