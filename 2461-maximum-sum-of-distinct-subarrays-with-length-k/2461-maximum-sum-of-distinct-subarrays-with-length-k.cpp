class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long int maxi=0,sum=0;
        map<int,int>m;
        for(int i=0;i<k;i++){
            sum+=nums[i];
            m[nums[i]]++;
        }
        
        if(m.size()==k){
            maxi=max(maxi,sum);
        }
        
        for(int i=k;i<nums.size();i++){
            sum += nums[i] - nums[i-k];
            m[nums[i-k]]--;
            if(m[nums[i-k]]==0){
                m.erase(nums[i-k]);
            }
            m[nums[i]]++;
            if(m.size()==k){
               maxi=max(maxi,sum); 
            }
        }
        return maxi;
    }
};