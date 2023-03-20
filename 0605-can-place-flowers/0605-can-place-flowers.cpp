class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        if(n == 0)
        {
            return true;
        }

        if(m == 1)
        {
            if(!flowerbed[0])
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        for(int i = 0; i < m; i++)
        {
            if(i == 0 && flowerbed[i] == 0 && flowerbed[i + 1] != 1)
            {
                n--;
                flowerbed[i] = 1;
            }
            if(i < m - 1 && flowerbed[i] == 0 && flowerbed[i + 1] != 1 && flowerbed[i - 1] != 1)
            {
                n--;
                flowerbed[i] = 1;
            }
            if(i == m - 1 && flowerbed[i] == 0 && flowerbed[i - 1] != 1)
            {
                n--;
                flowerbed[i] = 1;
            }
            if(n == 0)
            {
                return true;
            }
        }

        return n == 0;
    }
};