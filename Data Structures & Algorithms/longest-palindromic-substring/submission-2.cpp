class Solution {
   public:
    string longestPalindrome(string s) {
        int ans = 0;
        string a = "";
        int bestj = -1;
        int bestk = -1;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            // odd case
            int j = i, k = i;
            while (j >= 0 && k < n && s[j] == s[k]) {
                if (ans < k - j + 1) {
                    ans = max(ans, k - j + 1);
                    bestj = j;
                    bestk = k;
                }
                j--;
                k++;
            }

            // even case
            j = i - 1, k = i;
            while (j >= 0 && k < n && s[j] == s[k]) {
                if (ans < k - j + 1) {
                    ans = max(ans, k - j + 1);
                    bestj = j;
                    bestk = k;
                }
                j--;
                k++;
            }
        }
        return s.substr(bestj, ans);
    }
};
