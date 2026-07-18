class Solution {
    vector<vector<int>> dp;
   public:
    int helper(int i, vector<int>& s, int chance, int n) {
        // chance = 1 alice
        // chance = 0 bob
        if (i == n) {
            return 0;
        }
        if(dp[i][chance] != 1e8) return dp[i][chance];
        if (chance) {
            int score = -1e7;
            if (i < n - 2) {
                score = max(score, s[i] + s[i + 1] + s[i + 2] + helper(i + 3, s, !chance, n));
            }

            if (i < n - 1) {
                score = max(score, s[i] + s[i + 1] + helper(i + 2, s, !chance, n));
            }

            if (i < n) {
                score = max(score, s[i] + helper(i + 1, s, !chance, n));
            }

            return dp[i][chance] = score;
        }

        int score = 1e7;
        if (i < n - 2) {
            score = min(score, -(s[i] + s[i + 1] + s[i + 2]) + helper(i + 3, s, !chance, n));
        }

        if (i < n - 1) {
            score = min(score, -(s[i] + s[i + 1]) + helper(i + 2, s, !chance, n));
        }

        if (i < n) {
            score = min(score, -(s[i]) + helper(i + 1, s, !chance, n));
        }

        return dp[i][chance] = score;
    }
    string stoneGameIII(vector<int>& s) { 
        int n = s.size(); 
        dp.assign(n+1, vector<int>(2, 1e8));
        int ans = helper(0, s, 1, n);
        cout<<ans<<endl;
        if(ans == 0) return "Tie";
        else if(ans > 0) return "Alice";
        return "Bob";
        
        }
};