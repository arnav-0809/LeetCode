class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        string s;
        long long int ans=0;
        int n = nums.size();
        for(int i=0;i<n/2;i++){
            int x=nums[i];
            int y=nums[n-i-1];
            s=to_string(x) + to_string(y);
            ans+=stoi(s);
        }

        if(n%2){
            ans+=nums[n/2];
        }

        return ans;
    }
};