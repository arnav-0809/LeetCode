class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        set<int>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        nums.clear();
        for(auto&it:s){
            nums.push_back(it);
        }
        int maxi=1,count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]+1==nums[i]){
                count++;
            }else{
                count=1;
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};