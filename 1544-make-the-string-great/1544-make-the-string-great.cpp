class Solution {
public:
    string makeGood(string s) {
        int prev;
        do{
           prev=s.length();
            int n=s.length();
            for(int i = 0;i<n-1;i++){
                if(s[i]-'a' == s[i+1]-'A' || s[i]-'A' == s[i+1]-'a' ){
                    s.erase(i,2);
                }
            } 
        }
        while(s.length()<prev);
        return s;
    }
};