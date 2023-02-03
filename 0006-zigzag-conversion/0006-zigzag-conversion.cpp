class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;

        string ans="";
        int n=s.length();
        int cycle=numRows*2-2;

        for(int i=0;i<numRows;i++){
            for(int j=0;j+i<n;j+=cycle){
                ans+=s[i+j];
                
                if(i!=0 && i!=numRows-1 && j+cycle-i<n)
                    ans+=s[j+cycle-i];
            }
        }

        return ans;
    }
};