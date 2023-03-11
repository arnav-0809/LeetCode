class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int>m;
        int n = nums1.size(), s = nums2.size();
        for(int i = 0; i < n; i++)
        {
            m[nums1[i][0]] += nums1[i][1];
        }
        for(int i = 0; i < s; i++)
        {
            m[nums2[i][0]] += nums2[i][1];
        }    
        vector<vector<int>>ans;
        for(auto it : m)
        {
            ans.push_back({it.first, it.second});
        }
        return ans;
    }
};