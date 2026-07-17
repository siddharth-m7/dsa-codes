class Solution {
    vector<int> dp;
public:
    int helper(int n) {
        if(n == 0) 
            return 1;

        if(dp[n] != -1) return dp[n];
        int result = 0;
        for(int i = 1; i<=n; i++){
            result = max(result, i * helper(n-i));
        }
        return dp[n] = result;
    }
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;

        dp.assign(n+1, -1);
        return helper(n);
    }
};