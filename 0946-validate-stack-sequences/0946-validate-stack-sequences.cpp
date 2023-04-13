class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(), j = 0;
        stack<int> st;
        for(auto it : pushed)
        {
            st.push(it);
            while(st.size() && st.top() == popped[j])
            {
                st.pop();
                j++;
            }
        }
        return st.size() == 0;
    }
};