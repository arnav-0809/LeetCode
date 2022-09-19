class Solution {
public:
    void sol(vector<vector<int>>&ans, vector<int>&nums,int ind,int n,vector<int>&a){
        ans.push_back(a);
        for(int i=ind;i<n;i++){
            if(i!=ind && nums[i]==nums[i-1])continue;
            a.push_back(nums[i]);
            sol(ans,nums,i+1,n,a);
            a.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>a;
        sort(nums.begin(),nums.end());
        sol(ans,nums,0,nums.size(),a);
        return ans;
    }
};