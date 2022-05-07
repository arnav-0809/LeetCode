class Solution {
public:
    void g(vector<vector<int>>& pre,vector<int>adj[],vector<int>&in){
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            in[pre[i][0]]++;
        }
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>adj[n];
        vector<int>in(n,0);
        g(pre,adj,in);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            count++;
            for(auto it:adj[f]){
                in[it]--;
                if(in[it]==0){
                    q.push(it);
                }
            }
        }
        if(count!=n){
            return false;
        }
        
        return true;
    }
};