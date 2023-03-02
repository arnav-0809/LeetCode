class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, ans = 0;
        int n = chars.size();
        while (i < n) 
        {
            int j = 1;
            while (i + j < n && chars[i + j] == chars[i]) 
            {
                j++;
            }

            chars[ans] = chars[i];
            ans++;
            if (j > 1) 
            {
                for (char c : to_string(j)) 
                {
                    chars[ans] = c;
                    ans++;
                }
            }
            i += j;
        }
        return ans;
    }
};