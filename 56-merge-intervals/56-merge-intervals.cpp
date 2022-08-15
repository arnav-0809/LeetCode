class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int large;
        for(int i=0;i<intervals.size();i++){
            if(!ans.empty() && ans.back()[1]>=intervals[i][0]){
                large=max(intervals[i][1],ans.back()[1]);
                ans.back()[1]=large;
            }else{
                ans.push_back({intervals[i][0],intervals[i][1]});
            }
        }
        return ans;
    }
};