class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, 1e5);
        vector<int> ndp(amount+1, 1e5);

        for(int i=0; i<=n; i++){
            dp[0] = 0;
        }


        
        for(int i = 0; i<n; i++) {
            for(int j = 1; j<=amount; j++){
                if(coins[i] <= j) {
                    dp[j] = min(ndp[j], 1 + dp[j-coins[i]]);
                }
                else {
                    dp[j] = ndp[j];
                }
            }
            ndp = dp;
        }
        if(dp[amount] == 1e5) return -1;
        return dp[amount];

    }
};
