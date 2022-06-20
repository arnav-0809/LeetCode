class Solution {
public:
    static bool compare(string&a, string&b){
        return a.length()>b.length();
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        map<string,int>m;
        for(int i=0;i<words.size();i++){
            m[words[i]]=1;
        }
        int ans=0;
        for(int i=0;i<words.size();i++){
            int k=words[i].length();
            if(m[words[i]]==1){
                ans+=k+1;
            }
            
            for(int j=words[i].length()-1;j>=0;j--){
                if(m.find(words[i].substr(j,k-j))!=m.end()){
                    m[words[i].substr(j,k-j)]=0;
                }
            }
        }
        return ans;
    }
};