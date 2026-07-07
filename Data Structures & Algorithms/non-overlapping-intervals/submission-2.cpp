class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) { return a[1] < b[1]; });
        for (int i = 0; i < intervals.size(); i++) {
            int st = intervals[i][0];
            int end = intervals[i][1];
            while (i + 1 < intervals.size() && end > intervals[i + 1][0]) {
                end = min(intervals[i + 1][1], end);
                cnt++;
                i++;
            }
        }
        return cnt;
    }
};
