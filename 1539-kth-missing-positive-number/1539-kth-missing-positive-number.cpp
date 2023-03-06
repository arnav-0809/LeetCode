class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, n = arr.size();
        int r = n - 1;
        while(l <= r)
        {
            int m = l + (r - l) / 2;
            if(arr[m] - (m + 1) < k)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return l + k;
    }
};