class Solution {
public:
    int uniquePaths(int m, int n) {
        int x=m+n-2;
        double ans=1;
        int y=n-1;
        for(int i=1;i<=y;i++){
            ans=ans*(x-y+i)/i;
        }
        return (int)ans;
    }
};