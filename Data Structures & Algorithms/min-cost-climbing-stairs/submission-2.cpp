class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        int a = 0,b = 0,c = 0;
        for(int i = 2; i<=n; i++) {
            c = min({ cost[i-2] + a, cost[i-1] + b});
            a = b;
            b = c;
        }
        return c;
    }
};
