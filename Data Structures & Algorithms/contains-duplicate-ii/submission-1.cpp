class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i = 0; i<nums.size(); i++) {
            if(mpp.find(nums[i]) != mpp.end()) 
                if(mpp[nums[i]] != 0) return true;
            mpp[nums[i]]++;
            if(i>=k) mpp[nums[i-k]]--;
        }

        return false;
    }
};