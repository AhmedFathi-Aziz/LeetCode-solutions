class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int mini = 1e9;
        int index = 0;
        vector<int> prefix(n, 0);
        for (int i = 0; i < n; i++) {
            gas[i] = gas[i] - cost[i];
            prefix[i] = gas[i];
            if (i)
                prefix[i] += prefix[i - 1];
            if (prefix[i] < mini) {
                mini = prefix[i];
                index = i;
            }
        }
        if (prefix.back() < 0)
            return -1;
        ++index;
        index %= n;
        return index;
    }
};
