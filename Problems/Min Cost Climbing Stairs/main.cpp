class Solution {
public:
    int n;
    int dp[1000];
    int func(int i, vector<int> &cost) {
        if (i >= n)
            return 0;
        int &ret = dp[i];
        if (~ret)
            return ret;
        int one = func(i + 1, cost) + cost[i];
        int two = func(i + 2, cost) + cost[i];
        return ret = min(one, two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = (int) cost.size();
        memset(dp, -1, sizeof(dp));
        return min(func(0, cost), func(1, cost));
    }
};
