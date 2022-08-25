class Solution {
public:
    bool canConstruct(string r, string m) {
        map<char,int>a;
        map<char,int>b;
        for(int i=0;i<r.length();i++){
            a[r[i]]++;
        }
        
        for(int i=0;i<m.length();i++){
            b[m[i]]++;
        }
        
        for(auto it:a){
            if(b.find(it.first)!=b.end() && b[it.first]>=it.second)
                continue;
            else return false;
        }
        return true;
    }
};