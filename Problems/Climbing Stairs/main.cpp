class Solution {
public:
    int dp[46];
    int func(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int &ret = dp[n];
        if (~ret)
            return ret;
        return ret = func(n - 1) + func(n - 2);
    }
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return func(n);
    }
};
