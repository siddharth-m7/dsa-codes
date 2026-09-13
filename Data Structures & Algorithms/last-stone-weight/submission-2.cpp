class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin(), stones.end());
        int curr = 0, next= 0;
        while(!q.empty() && !(q.size() == 1)) {
            curr = q.top();
            q.pop();
            next = q.top();
            q.pop();
            int d = abs(curr - next);
            if(d != 0) {
                q.push(d);
            }
        }
        if(q.size() == 1)
            return q.top();
        return 0;
    }
};
