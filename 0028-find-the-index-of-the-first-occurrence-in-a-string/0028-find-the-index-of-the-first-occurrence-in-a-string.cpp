class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        if(m > n)
        {
            return -1;
        }

        string temp;
        for(int i = 0; i < n - m + 1; i++)
        {
            temp = haystack.substr(i, m);
            if(temp == needle)
            {
                return i;
            }
        }

        return -1;
    }
};