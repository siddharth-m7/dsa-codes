class Solution {
    vector<int> dp;
public:
    int helper(int i, int target, int n){
        
        if(target == 0) return 0;
        if(target < 0 ) return 1e5;
        if(i * i > n) return 1e5;

        if(dp[target] != 1e5) return dp[target];
        int pick = 1e5;
        for(int i = 1; i*i<=target; i++){
            pick = min(pick, 1 + helper(i, target-i*i, n));
        }
        return dp[target] = pick;
    }
    int numSquares(int n) {
        dp.assign(n+1, 1e5);
        return helper(1, n, n);
    }
};