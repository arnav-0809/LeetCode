class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int m=t.size();
        vector<int>prev(m,0),temp(m,0);;
        for(int i=0;i<m;i++){
            prev[i]=t[m-1][i];
        }
        
        for(int i=m-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int up=t[i][j]+prev[j];
                int leftUp=t[i][j]+prev[j+1];
                temp[j]=min(up,leftUp);
            }
            prev=temp;
        }
        
        return prev[0];
    }
};