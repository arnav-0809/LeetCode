class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.length(),n=s2.length();

        if(m>n){
            return false;
        }

        vector<int>v(26,0),v1(26,0);

        for(int i=0;i<m;i++){
            v[s1[i]-'a']++;
        }

        for(int i=0;i<m;i++){
            v1[s2[i]-'a']++;
        }

        for(int i=m;i<n;i++){
            if(v==v1)
                return true;
            v1[s2[i-m]-'a']--;
            v1[s2[i]-'a']++;
        }

        return v==v1;
    }
};