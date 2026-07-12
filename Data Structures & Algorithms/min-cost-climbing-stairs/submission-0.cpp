class Solution {
   public:
    int recur(int i, int n, vector<int>& cost, vector<int>& dp) {
        if (i == n) {
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        if (i == n - 1) {
            return dp[i] = cost[i] + recur(i + 1, n, cost, dp);
        }
        return dp[i] = min({cost[i] + recur(i + 1, n, cost, dp), cost[i] + recur(i + 2, n, cost, dp)});
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(recur(0, n, cost, dp), recur(1, n, cost, dp));
    }
};
