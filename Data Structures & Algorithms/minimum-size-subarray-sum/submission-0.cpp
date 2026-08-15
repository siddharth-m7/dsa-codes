class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int l =0, r = 0;
        int n = nums.size();
        int curr = 0;
        while(l<n && r<n){
            curr+=nums[r];
            while(curr >= target) {
                curr-=nums[l];
                ans = min(ans,r-l+1);
                l++;   
            }
            if(curr >= target)
                ans = min(ans,r-l+1);
            r++;
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};