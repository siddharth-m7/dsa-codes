class Solution {
public:
    int dfs(int l, int r,vector<int>& nums, vector<vector<int>>& dp){
        if(l>r) return 0;

        if(dp[l][r] != -1) return dp[l][r];
        int ans = 0;
        for(int i = l; i <=  r; i++){
            int num = nums[i];
            int currprod = nums[l-1] * nums[i] * nums[r+1];
            ans = max(ans, currprod + dfs(l, i-1,nums, dp) + dfs(i+1, r,nums, dp));
        }

        
        return dp[l][r] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);

        int n = nums.size() - 2;
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        return dfs(1, n, nums, dp);

    }
};
