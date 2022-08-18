class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>v;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
               long long int target2=1LL*target-1LL*nums[i]-1LL*nums[j];
               int l=j+1;
               int r=n-1;
               while(l<r){
                   long long int sum=1LL*nums[l]+1LL*nums[r];
                   if(sum<target2)l++;
                   else if(sum>target2)r--;
                   else{
                       v.push_back({nums[i],nums[l],nums[r],nums[j]});
                       int x=nums[l],y=nums[r];
                       while(l<r && nums[l]==x)++l;
                       while(l<r && nums[r]==y)--r;
                   }  
               }
               while(j+1<n && nums[j]==nums[j+1])j++;
           }
            while(i+1<n && nums[i]==nums[i+1])i++;
        }
        return v;
    }
};