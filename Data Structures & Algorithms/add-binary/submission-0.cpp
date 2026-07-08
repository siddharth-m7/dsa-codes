class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size()) return addBinary(b,a);

        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i;
        int carry = 0;
        string ans;
        ans.resize(a.size());
        for(i = 0; i<b.size(); i++) {
            int aa = int(a[i]) - 48;
            int bb = int(b[i]) - 48;

            if(aa + bb + carry == 3) {
                ans[i] = '1';
                carry = 1;
            }
            else if(aa + bb + carry == 2) {
                ans[i] = '0';
                carry = 1;
            }
            else if(aa + bb + carry == 1) {
                ans[i] = '1';
                carry = 0;
            }
            else {
                ans[i] = '0';
                carry = 0;
            }
        }

        for(;i<a.size(); i++){
            int aa = int(a[i]) - 48;
            if(aa + carry == 2) {
                ans[i] = '0';
                carry = 1;
            }
            else if(aa + carry == 1) {
                ans[i] = '1';
                carry = 0;
            }
            else {
                ans[i] = '0';
                carry = 0;
            }
        }
        if(carry) ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};