class Solution {
    vector<vector<vector<int>>> dp;
public:
    int helper(int i, vector<int>& prices, int last, bool own) {
        if(i == prices.size()) {
            return 0;
        }
        if(dp[i][last][own] != -1e9) return dp[i][last][own];
        // if i own, i can sell or skip
        // if i doesn't own i can buy or skip
        int profit = INT_MIN;
        // selling
        if(own) {
            profit = max(profit,prices[i] + helper(i+1, prices, i, !own));
        } 

        // buying
        if(!own && (last == prices.size() || i > last + 1)) {
            profit = max(profit,helper(i+1, prices, last, !own) - prices[i]);
        }

        // skip
        profit = max(profit,helper(i+1, prices, last, own));

        return dp[i][last][own] = profit;
        
    }
    int maxProfit(vector<int>& prices) {
        dp.assign(prices.size() + 1, vector<vector<int>>(prices.size() + 1, vector<int>(2, -1e9)));
        return helper(0, prices, prices.size(), false);
    }
};
