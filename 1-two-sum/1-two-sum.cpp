class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        map<int,int>m;
        for(int i=0;i<n.size();i++){
            m[n[i]]=i;
        }
        
        for(int i=0;i<n.size();i++){
            if(m.find(target-n[i])!=m.end() && m[target-n[i]]!=i){
                return {i,m[target-n[i]]};
            }
        }
        return {};
    }
};