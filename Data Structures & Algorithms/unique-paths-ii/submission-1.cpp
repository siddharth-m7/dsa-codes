class Solution {
private:
    vector<vector<int>> dp;

    int helper(int i, int j, int m, int n, vector<vector<int>>& obs) {
        if(i == m-1 && j == n-1) {
            return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int ch = 0;
        if(i < m-1 && obs[i+1][j] != 1) {
            ch += helper(i+1, j, m, n, obs);
        }
        if(j < n-1 && obs[i][j+1] != 1) {
            ch += helper(i, j+1, m, n, obs);
        }

        return dp[i][j] = ch;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
         
        int m = obs.size();
        int n = obs[0].size();
        if(obs[0][0] == 1 || obs[m-1][n-1] == 1) return 0;
        dp.assign(m, vector<int>(n, -1));
        return helper(0,0,m,n,obs);
    }
};

