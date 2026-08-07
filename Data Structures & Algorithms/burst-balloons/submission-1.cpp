class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        int n = nums.size() - 2;
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int l = n; l >= 1; l--) {
            for (int r = l; r <= n; r++) {
                for (int i = l; i <= r; i++) {
                    int currprod = nums[l - 1] * nums[i] * nums[r + 1];
                    currprod += dp[l][i - 1] + dp[i + 1][r];
                    dp[l][r] = max(dp[l][r], currprod);
                }
            }
        }
        return dp[1][n];
    }
};
