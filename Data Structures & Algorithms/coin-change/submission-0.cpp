class Solution {
    vector<vector<int>> dp;
public:
    int helper(int i, int t, vector<int>& coins) {
        // base 
        if(i == coins.size()) {
            if(t == 0) return 0;
            return 1e5;
        }

        if(dp[i][t] != -1) return dp[i][t];

        int notPick = helper(i+1, t, coins);

        int pick = 1e5;
        if(coins[i] <= t) {
            pick = 1 + helper(i, t-coins[i], coins);
        }

        return dp[i][t] = min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(coins.size() + 1, vector<int>(amount+1, -1));
        int ans = helper(0,amount, coins);
        if(ans == 1e5) 
        return -1;
        return ans;
    }
};
