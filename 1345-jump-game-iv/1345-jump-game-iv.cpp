class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), steps = INT_MAX;
        if(n == 1)
        {
            return 0;
        }

        map<int,set<int>>m;
        for(int i = 0; i < n; i++)
        {
            m[arr[i]].insert(i);
        }

        queue<pair<int,int>>q;
        vector<int>vis(n, 0);
        q.push({0, 0});
        
        while(!q.empty())
        {
            auto f = q.front();
            int lvl = f.second;
            int node = f.first;
            q.pop();
            vis[node] = 1;
            
            if(node == n - 1)
            {
                steps = min(lvl, steps);
            }

            for(auto it : m[arr[node]])
            {
                if(!vis[it])
                {   
                    q.push({it, lvl + 1});
                }
            }

            m.erase(arr[node]);

            if(node != 0 && !vis[node - 1])
            {
                q.push({node - 1, lvl + 1});
            }

            if(node != n - 1 && !vis[node + 1])
            {
                q.push({node + 1, lvl + 1});
            }
        }

        return steps;
    }
};