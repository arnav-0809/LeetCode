class Solution {
public:
    string removeStars(string s) {
        int n = s.length();
        string ans;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '*' && ans.length())
            {
                ans.pop_back();
            }
            else if(s[i] != '*')
            {
                ans += s[i];
            }
        }
        return ans;
    }
};