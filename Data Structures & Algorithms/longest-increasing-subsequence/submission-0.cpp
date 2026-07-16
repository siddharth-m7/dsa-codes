class Solution {
    vector<vector<int>> dp;
public:
    int lis(vector<int>& nums, int i, int lastpick, int n) {
        if(i == n){
            return 0;
        }

        if(lastpick != n && dp[i][lastpick] != -1) return dp[i][lastpick];

        int notPick = lis(nums, i+1, lastpick, n);

        int pick = 0;
        if(lastpick == n || nums[i] > nums[lastpick]) {
            pick = 1 + lis(nums, i+1, i, n);
        }

        return dp[i][lastpick] = max(pick, notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int> (n+1, -1));
        return lis(nums, 0, n, n);
    }
};
