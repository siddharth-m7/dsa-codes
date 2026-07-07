class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int ans = *max_element(nums.begin(), nums.end());

        for(auto n : nums){
            if(n + currSum <= 0) {
                currSum = 0;
            }
            else {
                currSum += n;
                ans = max(ans, currSum);
            }
        }
        return ans;
    }
};
