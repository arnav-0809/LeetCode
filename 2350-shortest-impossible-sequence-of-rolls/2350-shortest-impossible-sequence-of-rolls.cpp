class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        set<int>s;
        int ans=0;
        for(auto it:rolls){
            s.insert(it);
            if(s.size()==k){
                ans+=1;
                s.clear();
            }
        }
        return ans + 1;
    }
};