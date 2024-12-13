class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tank = 0;
        int longest = 0;
        for (int i = 0; i < n * 2; i++) {
            tank += gas[i % n] - cost[i % n];
            if (tank >= 0) {
               ++longest;
            } else {
                longest = 0;
                tank = 0;
            }
        }
        if (longest >= n)
            return 2 * n - longest;
        return -1;
    }
};
