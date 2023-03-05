class Solution {
public:
    int passThePillow(int n, int time) {
        int m = n - 1;
        int x = time / m;
        int y = time % m;
        if(x % 2)
        {
            return m - y + 1;
        }
        else
        {
            return y + 1;
        }
    }
};