class Solution {
public:
    int func(int index, int n, vector<int> &cost, vector<int> &memo) {
        if (index >= n)
            return 0;
        int &ret = memo[index];
        if (~ret)
            return memo[index];
        return ret = min(
            func(index + 1, n, cost, memo) + cost[index],
            func(index + 2, n, cost, memo) + cost[index]
        );
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(1001, -1);
        int n = cost.size();
        return min(func(0, n, cost, memo), func(1, n, cost, memo));
    }
};
