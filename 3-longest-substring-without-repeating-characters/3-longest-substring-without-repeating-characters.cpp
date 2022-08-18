class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>m;
        int count=0,maxi=0,start=0;
        for(int i=0;i<s.length();i++){
            if(m.find(s[i])!=m.end() && start<=m[s[i]]){
                start=m[s[i]]+1;
            }
            count=i-start+1;
            maxi=max(maxi,count);
            m[s[i]]=i;
        }
        return maxi;
    }
};