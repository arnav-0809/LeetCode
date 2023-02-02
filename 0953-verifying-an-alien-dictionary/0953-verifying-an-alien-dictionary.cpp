class Solution {
public:

    bool sol(string first, string second, map<char,int>&m){
        int n = min(first.length(), second.length());

        int i=0;
        while(i<n){
            if(m[first[i]]<m[second[i]]){
                return true;
            }else if(m[first[i]]>m[second[i]]){
                return false;
            }
            i++;
        }

        return first.length()<=second.length();
    }

    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        map<char,int>m;
        int j=0;
        for(int i=0;i<order.length();i++){
            m[order[i]]=j;
            j++;
        }

        for(int i=1;i<n;i++){
            if(!sol(words[i-1],words[i],m)){
                return false;;
            }
        }

        return true;
    }
};