class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long mini = nums[0];
        long long maxi = nums[0];
        long long ans = nums[0];
        long long currProd = nums[0];
        for (int i = 1; i < n; i++) {
            currProd = max({nums[i] * 1LL, maxi * nums[i], mini * nums[i]});
            ans = max(ans, currProd );
            mini = min({nums[i] * 1LL, maxi * nums[i], mini * nums[i]});
            maxi = currProd;
        }
        return (int)ans;
    }
};
