class Solution {
public:
    bool check(int i, vector<int> adj[], vector<int>& vis, vector<int>& dfsVis, stack<int>& st)
    {
        vis[i] = 1;
        dfsVis[i] = 1;
        for(auto it : adj[i])
        {
            if(!vis[it])
            {
                if(check(it, adj, vis, dfsVis, st))
                {
                    return true;
                }
            }
            else if(dfsVis[it])
            {
                return true;
            }
        }
        dfsVis[i] = 0;
        st.push(i);
        return false;
    }

    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> order, vis(n, 0), dfsVis(n, 0);
        vector<int> adj[n];
        stack<int> st;
        int m = pre.size();
        for(int i = 0; i < m; i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);    
        }

        for(int i = 0; i < n; i++)
        {
            if(!vis[i] && check(i, adj, vis, dfsVis, st))
            {
                return order;
            }
        }

        while(!st.empty())
        {
            auto it = st.top();
            st.pop();
            order.push_back(it);
        }
        return order;
    }
};