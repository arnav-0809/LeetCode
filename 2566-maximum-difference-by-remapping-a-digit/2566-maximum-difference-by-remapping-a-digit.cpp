class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int x = 0;
        char c;
        for(int i = 0; i < s.length(); i++)
        {
            if(x == 0 && s[i] != '9')
            {
                c = s[i];
                s[i] = '9';
                x = 1;
            }
            
            if(x == 1 && s[i] == c)
            {
                s[i] = '9';
            }
        }
        
        int maxi = stoi(s);
        s = to_string(num);
        x = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(x == 0)
            {
                c = s[i];
                s[i] = '0';
                x = 1;
            }
            
            if(x == 1 && s[i] == c)
            {
                s[i] = '0';
            }
        }
        int mini = stoi(s);
        return maxi - mini;
    }
};