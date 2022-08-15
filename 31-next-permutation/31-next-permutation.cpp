class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int r=-1,rev=0;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                r=i-1;
                break;
            }
        }
        
        if(r==-1){
            sort(nums.begin(),nums.end());
        }else{
            for(int i=n-1;i>r;i--){
                if(nums[i]>nums[r]){
                    rev=i;
                    break;
                }
            }
            swap(nums[rev],nums[r]);
            sort(nums.begin()+r+1,nums.end());
        }
    }
};