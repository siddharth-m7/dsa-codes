class Solution {
    vector<vector<int>> dp;
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        dp.assign(n + 1, vector<int>(2, 0));
        dp[1][1] = -prices[0];
        for(int i = 2; i<=prices.size(); i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1]);
            dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i-1]);
        }

        return dp[n][0];
    }
};
