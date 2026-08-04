class Solution {
   public:
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<bool>>& visited, int m, int n, vector<vector<int>>& dp) {
        if (i >= visited.size() || i < 0 || j < 0 || j >= visited[0].size()) {
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int dcol[] = {1, -1, 0, 0};
        int drow[] = {0, 0, 1, -1};
        int ans = 0;
        for (int k = 0; k < 4; k++) {
            int nrow = i + drow[k];
            int ncol = j + dcol[k];

            if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && !visited[nrow][ncol]) {
                if (matrix[nrow][ncol] > matrix[i][j]) {
                    visited[nrow][ncol] = true;
                    ans = max(ans, 1 + dfs(matrix, nrow, ncol, visited, m, n, dp));
                    visited[nrow][ncol] = false;
                }
            }
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                visited[i][j] = true;
                ans = max(ans,1 + dfs(matrix, i, j, visited, m, n, dp));
                visited[i][j] = false;
            }
        }
        return ans;
    }
};
