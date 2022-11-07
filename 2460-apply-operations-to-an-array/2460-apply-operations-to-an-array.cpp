class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]=2*nums[i];
                nums[i+1]=0;
            }
        }
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                q.push(i);
            }else{
                if(!q.empty()){
                    int f = q.front();
                    q.pop();
                    q.push(i);
                    swap(nums[f],nums[i]);
                }
            }
        }
        return nums;
    }
};