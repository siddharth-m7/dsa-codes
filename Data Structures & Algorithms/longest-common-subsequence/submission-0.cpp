class Solution {
public:
    int lcs(string& text1, string& text2, int i, int j, vector<vector<int>>& dp) {
        if(i == text1.size() || j == text2.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int m = 0;
        if(text1[i] == text2[j]) {
            return dp[i][j] = 1 + lcs(text1, text2, i+1, j+1, dp);
        }
        else {
            m = max(lcs(text1, text2, i, j+1, dp), lcs(text1, text2, i+1, j, dp));
        }
        return dp[i][j] = m;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return lcs(text1, text2, 0, 0, dp);
    }
};
