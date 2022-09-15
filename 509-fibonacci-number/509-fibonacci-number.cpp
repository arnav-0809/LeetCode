class Solution {
public:
    int fib(int n) {
        int prev1=0,prev=1;
        for(int i=2;i<=n;i++){
            int curr=prev+prev1;
            prev1=prev;
            prev=curr;
        }
        if(n==0)
            return 0;
        return prev;
    }
};