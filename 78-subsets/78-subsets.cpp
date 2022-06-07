class Solution {
public:
    void sol(vector<int>&nums,int size,vector<int>v,vector<vector<int>>&ans){
        if(size==nums.size()){
            ans.push_back(v);
            return;
        }
        
       
        v.push_back(nums[size]);
        sol(nums,size+1,v,ans);
        v.pop_back();
        sol(nums,size+1,v,ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        sol(nums,0,v,ans);
        return ans;
    }
};