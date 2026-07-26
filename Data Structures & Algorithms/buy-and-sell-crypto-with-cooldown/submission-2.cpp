class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int curr_hold = 0;
        int curr_no_hold = 0;
        int prev_hold = -prices[0];
        int prev_no_hold = 0;
        int prev_prev_no_hold = 0;
        for(int i = 2; i<=prices.size(); i++) {
            curr_no_hold = max(prev_no_hold, prev_hold + prices[i-1]);
            curr_hold = max(prev_hold, prev_prev_no_hold - prices[i-1]);

            prev_prev_no_hold = prev_no_hold;
            prev_no_hold = curr_no_hold;
            prev_hold = curr_hold;
        }

        return curr_no_hold;
    }
};
