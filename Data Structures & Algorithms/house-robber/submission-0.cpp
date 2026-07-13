class Solution {
private: 
    vector<int> dp;
public:
    int dfs(vector<int>& nums, int i) {
        // base case 
        if( i >= nums.size()) 
        {
            return 0;
        }

        if(dp[i] != -1) return dp[i];


        // chori krlo 
        int ch = nums[i] + dfs(nums, i+2);

        ch = max(ch, dfs(nums, i+1));

        return dp[i] = ch;
    }

    int rob(vector<int>& nums) {
        dp.assign(nums.size()+1, -1);
        return dfs(nums,0);
    }
};
