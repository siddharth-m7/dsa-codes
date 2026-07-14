class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            // odd case
            int j = i, k = i;
            while (j >= 0 && k < n && s[j] == s[k]) {
                ans++;
                j--;
                k++;
            }

            // even case
            j = i - 1, k = i;
            while (j >= 0 && k < n && s[j] == s[k]) {
                ans++;
                j--;
                k++;
            }
        }
        return ans;
    }
};
