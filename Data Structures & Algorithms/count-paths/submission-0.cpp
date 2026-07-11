class Solution {
    private:
    vector<vector<int>> dp;
public:
    int helper(int i, int j, int m, int n) {
        if(i == m-1 && j == n-1) {
            return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int ch = 0;
        if(i < m-1) {
            ch += helper(i+1, j, m, n);
        }
        if(j < n-1) {
            ch += helper(i, j+1, m, n);
        }

        return dp[i][j] = ch;
    }

    int uniquePaths(int m, int n) {
        dp.assign(m, vector<int>(n, -1));
        return helper(0,0,m,n);
    }
};
