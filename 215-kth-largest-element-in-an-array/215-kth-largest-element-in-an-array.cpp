class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int>p;
        for(int i=0;i<n;i++){
            p.push(nums[i]);
        }
        while(p.size()>n-k+1){
            p.pop();
        }
        return p.top();
    }
};