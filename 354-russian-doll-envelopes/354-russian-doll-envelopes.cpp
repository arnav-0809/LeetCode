class Solution {
public:
    
    int maxEnvelopes(vector<vector<int>>& v) {
        int n=v.size();
        sort(v.begin(),v.end(),[&](const vector<int> &a,const vector<int> &b){
        if(a[0]==b[0])
            return a[1]>b[1];
            return a[0]<b[0];
        });
        vector<int>ans(n);
        
        for(int i=0;i<n;i++){
            ans[i] = v[i][1];
        }
        
        vector<int>dp;
        dp.push_back(ans[0]);
        for(int i=1;i<n;i++){
            if(ans[i]>dp.back()){
                dp.push_back(ans[i]);
            }else{
                auto it=lower_bound(dp.begin(),dp.begin()+dp.size(),ans[i])-dp.begin();
                dp[it]=ans[i];
            }
        }
        
        return dp.size();
    }
};