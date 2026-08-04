class Solution {
    private:
    vector<vector<vector<int>>> dp;
public:
    int helper(int i, int m, vector<int>& piles, bool turn) {
        if(i >= piles.size()){
            return 0;
        }
        if(dp[i][m][turn] != -1) return dp[i][m][turn];
        // turn = true for alice
        if(turn) {
            int curr = 0;
            int ans = -1e9;
            for(int j = 0; j < 2 * m; j++){
                // cout<<j<<endl;
                if(i+j >= piles.size()) break;
                curr += piles[i+j];
                ans = max(ans, curr + helper(i+j+1, max(m,j+1), piles, !turn));
            }
            return dp[i][m][turn] = ans;
        }
        else {
            int curr = 0;
            int ans = 1e9;
            for(int j = 0; j < 2 * m; j++){
                if(i+j >= piles.size()) break;
                curr += piles[i+j];
                ans = min(ans, helper(i+j+1, max(m,j+1), piles, !turn));
            }
            return dp[i][m][turn] = ans;
        }
        return 0;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        return helper(0, 1, piles, true);
    }
};