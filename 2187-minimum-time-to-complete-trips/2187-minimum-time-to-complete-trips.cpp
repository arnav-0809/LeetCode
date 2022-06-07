class Solution {
public:
    long long int sol(vector<int>& time, long long int m){
        long long total=0;
        for(int i=0;i<time.size();i++){
            total+=m/time[i];
        }
        return total;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int l=0,h=1e14;
        long long int ans=0;
        while(l<=h){
            long long int m=l+(h-l)/2;
            if(sol(time,m)>=totalTrips){
                h=m-1;
                ans=m;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};