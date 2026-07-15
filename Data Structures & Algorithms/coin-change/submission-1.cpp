class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount+1, 1e5));

        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
        }
        
        for(int i = 0; i<n; i++) {
            for(int j = 1; j<=amount; j++){
                if(coins[i] <= j) {
                    dp[i+1][j] = min(dp[i][j], 1 + dp[i+1][j-coins[i]]);
                }
                else {
                    dp[i+1][j] = dp[i][j];
                }
                cout<<dp[i+1][j]<<endl;
            }
            cout<<endl;
        }
        if(dp[n][amount] == 1e5) return -1;
        return dp[n][amount];

    }
};
