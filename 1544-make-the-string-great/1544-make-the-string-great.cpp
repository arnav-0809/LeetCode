class Solution {
public:
    string makeGood(string s) {
        stack<char>st,st1;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(!st.empty() && (s[i]-'a'==st.top()-'A' || s[i]-'A' == st.top()-'a')){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        
        while(!st.empty()){
            st1.push(st.top());
            st.pop();
        }
        
        while(!st1.empty()){
            ans+=st1.top();
            st1.pop();
        }
        return ans;
    }
};