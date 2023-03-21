//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void topoSort(int i, vector<pair<int, int >> adj[], vector<int>& vis, stack<int> & st) 
    {
        vis[i] = 1;
        for (auto it: adj[i]) 
        {
          int v = it.first;
          if (!vis[v]) 
          {
            topoSort(v, adj, vis, st);
          }
        }
        st.push(i);
    }
    
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int, int>> adj[N];
        for(auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> vis(N, 0), dis(N, 1e9);
        stack<int> st;
        for (int i = 0; i < N; i++) 
        {
          if (!vis[i]) 
          {
            topoSort(i, adj, vis, st);
          }
        }
        
        dis[0] = 0;
        while(!st.empty())
        {
            auto t = st.top();
            st.pop();
            for(auto it : adj[t])
            {
                int f = it.first, s = it.second;
                if(dis[t] + s < dis[f])
                {
                    dis[f] = dis[t] + s;
                }
            }
        }
        
        for(int i = 0; i < N; i++)
        {
            if(dis[i] == 1e9)
            {
                dis[i] = -1;
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends