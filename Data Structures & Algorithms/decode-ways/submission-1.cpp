class Solution {
public:
    int helper(int i, string& s, vector<int>& dp) {
        if( i > s.size()){
            return 0;
        }
        if( i == s.size()){
            return 1;
        }

        if(dp[i] != -1) return dp[i];

        if(s[i] == '0') return 0;

        int one = helper(i+1, s, dp);
        int two = 0;
        if(i < s.size()-1 && (s[i] == '1' || s[i] == '2')) {
            if(s[i] == '1') {
                two = helper(i+2, s, dp);
            }
            if(s[i] == '2' && s[i+1] >= '0' && s[i+1] <= '6')
                two = helper(i+2, s, dp);
        }

        return dp[i] = one + two;



    }
    int numDecodings(string s) {
        vector<int> dp(100+1, -1);
        return helper(0,s,dp);
    }
};
