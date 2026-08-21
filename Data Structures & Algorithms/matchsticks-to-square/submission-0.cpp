class Solution {
public:
    bool dfs(vector<int>& m, int i, int a, int b, int c, int d) {
        if( i == m.size()) {
            if(a == b && b == c && c == d && d == 0) return true;
            return false;
        }
        bool ans = false;
        if(m[i] <= a) {
            ans = ans || dfs(m, i+1, a-m[i], b, c, d);
        }
        if(m[i] <= b) {
            ans = ans || dfs(m, i+1, a, b-m[i], c, d);
        }
        if(m[i] <= c) {
            ans = ans || dfs(m, i+1, a, b, c-m[i], d);
        }
        if(m[i] <= d) {
            ans = ans || dfs(m, i+1, a, b, c, d-m[i]);
        }
        return ans;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum%4 != 0) return false;
        return dfs(matchsticks,0,sum/4, sum/4, sum/4, sum/4);
    }
};