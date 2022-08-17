class Solution {
public:
    vector<int> majorityElement(vector<int>& n) {
        vector<int>ans;
        int c1=0,c2=0,n1=INT_MIN,n2=INT_MIN;
        for(int i=0;i<n.size();i++){
            if(n[i]==n1){
                c1++;
            }else if(n[i]==n2){
                c2++;
            }else if(c1==0){
                n1=n[i];
                c1++;
            }else if(c2==0){
                n2=n[i];
                c2++;
            }else{
                c1--;
                c2--;
            }
        }
        
        c1=0,c2=0;
        for(int i=0;i<n.size();i++){
            if(n1==n[i])
                c1++;
            else if(n2==n[i])
                c2++;
        }
        
        if(c1>n.size()/3)
            ans.push_back(n1);
        if(c2>n.size()/3)
            ans.push_back(n2);
        return ans;
    }
};