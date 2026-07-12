class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        int a = 0;
        int b = 1;
        int c = 1;
        for(int i=n-1; i>=0; i--){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
