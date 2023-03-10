class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        int n = s.length();
        int k = 0, minSum = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            minSum += (s[i] - '0') * pow(10, k / 2);
            k++;
        }
        
        return minSum;
    }
};