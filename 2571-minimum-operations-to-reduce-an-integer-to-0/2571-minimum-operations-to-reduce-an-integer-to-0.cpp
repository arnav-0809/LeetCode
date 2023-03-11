class Solution {
public:
    int minOperations(int n) {
        if(n == 0 || n == 1)
        {
            return n;
        }
        int x = 1;
        while(x * 2 < n)
        {
            x = x * 2;
        }
        
        return 1 + min(minOperations(x * 2 - n), minOperations(n - x));
    }
};