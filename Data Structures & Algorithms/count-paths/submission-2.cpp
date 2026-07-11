class Solution {
    private:
    vector<int> dp;
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,0);
        vector<int> pdp(n,0);
        dp[0] = 1;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++) {
                if(i > 0 && j>0) {
                    dp[j] = pdp[j] + dp[j-1];
                }
                else if(i>0){
                    dp[j] = pdp[j];
                }
                else if(j>0){
                    dp[j] = dp[j-1];
                }
                
            }
            pdp = dp;
        }
        return dp[n-1];
    }
};
