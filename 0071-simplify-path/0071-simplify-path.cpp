class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.length();
        string ans;
        for(int i = 0; i < n; i++)
        {
            if(path[i] == '/')
            {
                continue;
            }
            string s;

            while(i < n && path[i] != '/')
            {
                s += path[i];
                i++;
            } 

            if(s == ".")
            {
                continue;
            }
            else if(s == "..")
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(s);
            }
        }

        while(!st.empty())
        {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        if(!ans.length())
        {
            return "/";
        }
        return ans;
    }
};