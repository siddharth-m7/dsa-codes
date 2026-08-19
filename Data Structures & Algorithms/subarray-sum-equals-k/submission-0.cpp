class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        int currSum = 0;
        int cnt = 0;

        for(int n : nums) {
            currSum += n;
            
            if(mpp.find(currSum - k) != mpp.end()) {
                cnt += mpp[currSum-k];
            }

            mpp[currSum]++;
        }
        return cnt;
    }
};