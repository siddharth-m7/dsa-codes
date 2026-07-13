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
        int n = nums.size();
        dp.assign(n+1, 0);
        dp[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            if(i<n-2) {
                dp[i] = max(dp[i+1], nums[i] + dp[i+2]);
            }
            else {
                dp[i] = max(dp[i+1], nums[i]);
            }  
        }
        return dp[0];
    }
};
