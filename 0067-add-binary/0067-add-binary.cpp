class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length(), n = b.length();
        string ans = "";
        if(m > n){
            int x = m - n;
            string str(x, '0');
            str += b;
            b = str;
        }else{
            int x = n - m;
            string str(x, '0');
            str += a;
            a = str;
        }

        int y = max(m, n);
        int carry = 0;
        for(int i = y - 1; i >= 0; i--){
            if(a[i] == '1' && b[i] == '1'){
                if(carry == 1){
                    ans += '1';
                }else{
                    ans += '0';
                    carry = 1;
                }
            }else if(a[i] == '0' && b[i] == '0'){
                if(carry == 1){
                    ans += '1';
                    carry = 0;
                }else{
                    ans += '0';
                }
            }else{
                if(carry == 1){
                    ans += '0';
                }else{
                    ans += '1';
                }
            }
        }

        if(carry == 1){
            ans += '1';
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};