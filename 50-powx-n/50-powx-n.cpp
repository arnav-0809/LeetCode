class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long long int m=abs(n);
        while(m){
            if(m%2){
                ans=ans*x;
                m-=1;
            }else{
                x=x*x;
                m/=2;
            }
        }
        
        if(n>=0)
            return ans;
        return (double)1/ans;
    }
};