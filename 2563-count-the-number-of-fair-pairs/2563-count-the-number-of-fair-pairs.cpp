class Solution {
public:
    long long countFairPairs(vector<int>& nums, int l, int u) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=n-1;
        long long int pairs=0;
        while(i<j){
            if(nums[i]+nums[j]<=u){
                pairs+=j-i;
                i++;
            }else{
                j--;
            }
        }
        
        i=0,j=n-1;
        while(i<j){
            if(nums[i]+nums[j]<l){
                pairs-=j-i;
                i++;
            }else{
                j--;
            }
        }
        return pairs;
    }
};