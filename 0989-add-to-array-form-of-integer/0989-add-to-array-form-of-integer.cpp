class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        stack<int> s;
        vector<int> v;
        while(k){
            int x = k % 10;
            s.push(x);
            k /= 10;
        }

        while(!s.empty()){
            int t = s.top();
            v.push_back(t);
            s.pop();
        }

        int m = v.size();
        int maxi = max(m, n);
        if(n > m){
            v.insert(v.begin(), n - m, 0 );
        }else{
            num.insert(num.begin(), m - n, 0 );
        }

        int carry = 0;
        for(int i = maxi - 1 ; i >= 0; i--){
            int y = num[i] + v[i];
            if(carry == 1 ){
                y += 1;
            }

            if(y >= 10){
                carry = 1;
                num[i] = y % 10;
            }else{
                carry = 0;
                num[i] = y;
            }
        }

        if(carry == 1){
            num.insert(num.begin(), 1);
        }

        return num;
    }
};