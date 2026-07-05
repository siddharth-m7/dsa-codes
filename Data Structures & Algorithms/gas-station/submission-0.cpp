class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = -1;
        int n = gas.size();
        for(int i = 0; i < n; i++) {
            int currGas = 0;
            bool flag = true;

            for(int j = i; j < i+n; j++) {
                currGas+= (gas[j%n] - cost[j%n]);
                if(currGas < 0) {
                    flag = false;
                }
            }
            if(flag) {
                ans = i;
            }
        }
        return ans;
    }
};
