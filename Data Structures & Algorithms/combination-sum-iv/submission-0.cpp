class Solution {
public:
    int dfs(vector<int>& nums, int target, vector<int>& dp){
        if(target == 0) {
            return 1;
        }

        if(dp[target] != -1) return dp[target];

        int total = 0;
        for(auto n : nums) {
            if(target >= n){
                total += dfs(nums, target-n, dp);
            }
        }
        return dp[target] = total;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return dfs(nums, target, dp);
    }
};